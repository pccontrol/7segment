
#include "Segment3inch.h"

#define pinClock    6
#define pinLatch    7
#define pinData     8

Segment3inch displayku(pinClock, pinLatch, pinData);

void setup() {
  // put your setup code here, to run once:

}

void loop()
 {
  // put your main code here, to run repeatedly:
display7segment(123,1000,999);
}

void display7segment(int row1, int row2, int row3)
{

  display7Seg.writeAngka(row3, 4); //tahun
  display7Seg.writeAngka(row2, 4); //tahun
  display7Seg.writeAngka(row1, 4); //tahun  
  display7Seg.strobe_74595();
}
