/*
  Segment.cpp - Library for 7 Segment code.
  Created by Dani KCM , November 2, 2011.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Segment3inch.h"
/*

unsigned char textdata[]=
{
  //Hbaf gcde

  0b01110111, //untuk angka 0  
  0b01000100, //untuk angka 1
  0b01101011, //untuk angka 2
  0b01101110, //untuk angka 3
  0b01011100, //untuk angka 4
  0b00111110, //untuk angka 5
  0b00111111, //untuk angka 6
  0b01100100, //untuk angka 7
  0b01111111, //untuk angka 8
  0b01111110, //untuk angka 9
  0b00000000,//10    //blank
  0b00001000,// -  //minus 11
0b01101111,//  a 12
0b00011111,//  b 13
0b00001011,//  c 14
0b01001111,//  d 15
0b00111011,//  E 16
0b00111001,//  F 17
0b01111110,//  g 18
0b00011101,//  h 19
0b00000001,//  i 20
0b00100110,//  j 21
0b00011011,//  k 22
0b00010011,//  L 23
0b01110101,//  m 24  xxx
0b00001101,//  n 25
0b00001111,//  o 26
0b01111001,//  P 27
0b01111001,//  q 28
0b00001001,//  r 29
0b00111110,//  S 30
0b00011011,//  t 31
0b00000111,//  u 32
0b00000111,//  V 33  xxx
0b00000111,//  w 34  xxx
0b00000111,//  x 35
0b01011110,//  y 36
0b01101011, // z 37
0b00010001,  // I 38
0b00010101,  // Ii 39  
0b00001010,  // _eq (=) 40
0b11000100, //41 untuk angka 1.
0b11101011, //42 untuk angka 2.
0b10000000  // _dot 43

 }; 
*/
 unsigned char textdata[]=
{
//cdeg baPf
0b11101111,//0
0b10001010, //1 0b10001000, //1
0b01111110, //2 
0b11011110, //3
0b10011011, // 4
0b11010111, //5
0b11110111, //6
0b10001110, //7
0b11111111, //8
0b11011111, //9
0b00000010, //10    //blank
0b00010010, // -  //minus 11
0b11111100,//12a
0b11110001,//13b
0b01110000,//14c
0b11111000,//15d
0b01110101,//16e
0b00110101,//17f
0b11011101,//18g
0b10110001,//19h
0b10001000,//20i
0b11001000,//21j
0b01110001,//22k
0b01100001,//23l
0b10101101,//24m
0b10110000,//25n
0b11110000,//26o
0b00111101,//27p
0b10011101,//28q
0b00110000,//29r
0b11010101,//30s
0b01110001,//31t
0b11100000,//32u
0b11100000,//33v
0b10100000,//34w
0b10110100,//35x
0b10011001,//36y
0b01111100,//37z
0b00100001,//38I
0b10100001,//39li
0b01010000,//40_eg
0b10001010,//411.
0b01111100,//422.
0b00000010//43dot


 };
Segment3inch::Segment3inch(int pinClock, int pinLatch, int pinData)
{
  pinMode(pinClock , OUTPUT);
  _pinClock = pinClock;
   pinMode(pinLatch, OUTPUT);
  _pinLatch = pinLatch;
   pinMode(pinData, OUTPUT);
  _pinData = pinData;
  
}

void Segment3inch::clock_74595()
{
    clock_hi; 
    delay(1);
    clock_lo;
}

void Segment3inch::strobe_74595()
{
    strobe_hi;
    delay(1);
    strobe_lo;   
}

void Segment3inch::writeAbjad(int abjad)
{
  kirimbyte74595(~textdata[abjad]);
}

void Segment3inch::writeAngka(long dat, char digit)
{ 
  unsigned char j,sign=1;  
  unsigned char angka;
  
  if(dat<0)
  {
  dat= dat * -1;
  sign=0;
   }
  
  for(j=0;j<digit;j++) 
{ 

angka=dat%10; 
 dat /= 10;           //6/10 
 
if(angka==0)
{  
if(dat==0) 
{
  if(sign==1 && j>0)   
  {
  angka=10; // blank      
  }  
else
angka=0; // 0   
  
  if(sign==0)
    {
    angka=11; //tanda minus 11
    sign=1;
    }
 }
} 
kirimbyte74595(~textdata[angka]);            
}  //end for
 } //end methode/function 
 
void Segment3inch::kirimbyte74595(unsigned char dataku)
{
    unsigned char dataled;
    dataled=dataku;
    if(dataled&(1<<7))data_hi;else data_lo;     
    clock_74595();
    if(dataled&(1<<6))data_hi;else data_lo;     
    clock_74595();
    if(dataled&(1<<5))data_hi;else data_lo;     
    clock_74595();
    if(dataled&(1<<4))data_hi;else data_lo;     
    clock_74595();
    if(dataled&(1<<3))data_hi;else data_lo;     
    clock_74595();
    if(dataled&(1<<2))data_hi;else data_lo;     
    clock_74595();
    if(dataled&(1<<1))data_hi;else data_lo;     
    clock_74595();
    if(dataled&(1<<0))data_hi;else data_lo;     
    clock_74595();   
}

void Segment3inch::printKata(int a,int b,int c,int d)  
{   
  writeAbjad(d);
  writeAbjad(c);
  writeAbjad(b);
  writeAbjad(a);  
}
