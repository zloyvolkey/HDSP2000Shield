/* HDSP2000 LED Library
   W. Esposito.
   July 2013

*/


#ifndef _HDSP2000_
#define _HDSP2000_

#include <avr/io.h>
#include <avr/interrupt.h>

#define RESOLUTION 65536    // Timer1 is 16 bit


//Pin Defines
#define dispCount 2
#define COL1 3
#define COL2 4
#define COL3 5
#define COL4 6
#define COL5 7
#define VB 4
#define CLK 8
#define DIN 9

class HDSP2000Shield
{
	private:
		int bus[5]; //array of colunm pins
		long buildCol(unsigned char* string, int disp, int col);
		void shiftlong(long val);
		int curCol; //start at beginning.
		void setPeriod(long microseconds);
		unsigned int pwmPeriod;
		unsigned char clockSelectBits;
		char oldSREG;					// To hold Status Register while ints disabled
	public:
		HDSP2000Shield();
		void driveDisplay();
		void begin(int refreshRate = -1);
		void end();
		char txtBuffer[25];
};

extern HDSP2000Shield HDSP2000;

#endif
