/* example.cpp
 * multi Byte Serial Library for Arduino
 * release:  1.0,  November 5, 2011
 * "Serial, it's what is for breakfast."
 *
 * by:  James Lewis (jamesC4S), byerly0503@gmail.com
 *
 */
#include "WProgram.h"
#include "arduino.h"

#include "SerialInput.h"

SerialInput serNum;

void setup() {
	Serial.begin(9600);
	serNum.setDecimalChar('.');
}

void loop() {
	if (Serial.available() > 0) {
		serNum.addChar(Serial.read());
		if (serNum.error) {
			Serial.println("Error");
			serNum.error = false; // clear error flag
		}
		if (serNum.numberReady) {
			Serial.print("Recv'd: ");
			Serial.println(serNum.receivedNumber);
			serNum.clearNumber();
		}
	}
}


// Delete when moving to the Arduino IDE...
int main(void)
{
	init();
	setup();
	for (;;)
		loop();
	return 0;
}
