#include "defines.h"

void button_config() {
	pinMode(SW1, INPUT);
	pinMode(SW2, INPUT);
	pinMode(SW3, INPUT);
	pinMode(SW4, INPUT);
	digitalWrite(SW1, HIGH);
	digitalWrite(SW2, HIGH);
	digitalWrite(SW3, HIGH);
	digitalWrite(SW4, HIGH);
}
