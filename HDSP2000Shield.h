/* HDSP2000 LED Library
   W. Esposito.
   July 2013

*/


#ifndef _HDSP2000_
#define _HDSP2000_

#include <avr/io.h>
#include <avr/interrupt.h>

#define RESOLUTION 65536    // Timer1 is 16 bit

class HDSP2000Shield
{
	private:
		int dispCount = 0;
		int _column1 = 0;
		int _column2 = 0;
		int _column3 = 0;
		int _column4 = 0;
		int _column5 = 0;
		int _vb = 0;
		int _clock = 0;
		int _din = 0;

		bool initialized = false;

		int bus[5]; //array of colunm pins
		long buildCol(unsigned char* string, int disp, int col);
		void shiftlong(long val);
		int curCol; //start at beginning.
		void setPeriod(long microseconds);
		unsigned int pwmPeriod;
		unsigned char clockSelectBits;
		char oldSREG;					// To hold Status Register while ints disabled
	public:
		HDSP2000Shield(int displayCount, int col1, int col2, int col3, int col4, int col5, int clock, int din);
		void driveDisplay();
		void begin(int refreshRate = -1);
		void end();
		char txtBuffer[25];
};

extern HDSP2000Shield HDSP2000;

#endif
