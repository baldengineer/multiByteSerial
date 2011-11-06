/*
	SerialInput.h - Library for converting serial input into numbers.
	Created by James C Lewis, Oct-15-2011.  byerly0503@gmail.com, www.cmiyc.com
	Released into the public domain.
*/
#ifndef SerialInput_h
#define SerialInput_h

#include "WProgram.h"

class SerialInput
{
	public:
		SerialInput();
		void addChar(char c);
		void clearNumber();
		void setComma(int comma);
		void setDecimalChar(int decCharacter);
		bool error;
		float receivedNumber;
		bool numberReady;
		bool receivedDecimalPoint;
		int decimalCharacter;

	private:
		float mantissa;
		float decimal;
		int index;
};

#endif
