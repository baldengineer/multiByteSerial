/* SerialInput.h - Library for converting serial input into numbers.
	Created by James C Lewis, Oct-15-2011.  byerly0503@gmail.com, www.cmiyc.com
	Released into the public domain.
 */

#include "WProgram.h"
#include "SerialInput.h"
//#include "Math.h"

SerialInput::SerialInput()
{
	receivedNumber = 0.0;
	mantissa = 0.0;
	decimal = 0.0;
	index = 0;

	decimalCharacter = 46;
	numberReady = false;
	receivedDecimalPoint = false;
	error = false;
}

void SerialInput::addChar(char c) {
	switch (c) {
	case 8:				// ignore backspaces
	case 127:			// and deletes
		error = true;	// raise error flag until figure out how to fix it.
		break;

	case 10:
	case 13:
		numberReady = true;
		break;

	case 44:	// handle commas and decimals
	case 46:	// default to the US standard of "," as the comma.  ignore the unused character
		if (c == decimalCharacter) {	// if the currently set decimal character comes in,
			receivedDecimalPoint = true;
			//Serial.println();
			index = 0;
		}
		break;

	default:
		if ((c >= 48) && (c <= 57)) { // skip anything that isn't an integer
			index++;
			if (receivedDecimalPoint) {	//build the mantissa and decimal separately
				decimal = decimal * 10.0 + c-48.0;
			} else {
				mantissa = mantissa * 10.0 + c-48.0;
			}
			float multi=1;
			for(int i=0; i<index; i++) {	// received a decimal, time to figure out how far to shift it over
				multi = multi * 10;
			}
			receivedNumber = mantissa + (decimal/multi); // this shifts the decimal before adding to the whole number
			//Serial.print("Received: ");
			//Serial.println(receivedNumber);
		} else {
			error = true;
		}
		break;
	}
}

void SerialInput::setDecimalChar(int decCharacter) {
	decimalCharacter = decCharacter;
}

void SerialInput::clearNumber() {
	error = false;
	numberReady = false;
	receivedNumber = 0.0;
	mantissa = 0.0;
	decimal = 0.0;
	index=0;
	receivedDecimalPoint = false;
}
