/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef Segment3inch_h
#define Segment3inch_h

#include "Arduino.h"

#define data_hi    digitalWrite(_pinData, HIGH)
#define data_lo    digitalWrite(_pinData, LOW)

#define strobe_hi    digitalWrite(_pinLatch, HIGH)
#define strobe_lo    digitalWrite(_pinLatch, LOW)

#define clock_hi    digitalWrite(_pinClock, HIGH)
#define clock_lo    digitalWrite(_pinClock, LOW)

#define    _a 12
#define    _b 13
#define    _c 14
#define    _d 15
#define    _e 16
#define    _f 17
#define    _g 18
#define    _h 19
#define    _i 20
#define    _j 21
#define    _k 22
#define    _l 23
#define    _m 24
#define    _n 25
#define    _o 26
#define    _p 27
#define    _q 28
#define    _r 29
#define    _s 30
#define    _t 31
#define    _u 32
#define    _v 33
#define    _w 34
#define    _x 35
#define    _y 36
#define    _z 37
#define    _I 38
#define    _Ii 39
#define    _eq  40
#define    _1dot  41
#define    _2dot  42
#define    _dot  43




class Segment3inch
{
  public:
  
    Segment3inch(int pinClock, int pinLatch, int pinData);
    void writeAngka(long dat, char digit);
    void printKata(int a,int b,int c,int d);  
	void writeAbjad(int abjad);
   void strobe_74595();
   
  private:
  void clock_74595();
  void kirimbyte74595(unsigned char dataku);
 
    int _pinClock;
	int _pinLatch;
	int _pinData;
};

#endif

