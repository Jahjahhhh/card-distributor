#include <Servo.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "defines.h"
#include "button_config.h"

Servo ESC;
byte speed = 0;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup(void) {
	Serial.begin(9600);

	// SSD1306_SWITCHAPVCC = generate display voltage from 3.3V internally
	if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
		Serial.println(F("SSD1306 allocation failed"));
		for(;;); // Dont proceed, stay stuck here.
	}

	print_text("balls");
  while(1);

	button_config(); // Configures the buttons
	
	ESC.attach(ESC_PIN, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
	ESC.write(0); // ESC will not be happy otherwise
	delay(5000);     // Wait for the calibration to be done
}

void loop(void) {
	byte incr, decr;
	do {
		incr = digitalRead(SW2);
		decr = digitalRead(SW3);
	} while(incr && decr);
	delay(50);

	incr == 0 ? speed++ : speed--;
	ESC.write(speed);
}

void print_text(const char* text) {
	display.clearDisplay();
	display.setTextSize(2);
	display.setTextColor(SSD1306_WHITE);
	display.setCursor(0,0);
	display.println(F(text));
	display.display();
	delay(100);
}
