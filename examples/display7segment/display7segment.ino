
#include "Segment3inch.h"

Segment3inch displayku(6,7,8); //clock-strobe-data

void setup() {
  // put your setup code here, to run once:

}

void loop()
 {
  // put your main code here, to run repeatedly:
displayku.writeAngka(123,4);
displayku.writeAngka(456,4);
displayku.writeAngka(789,4);
displayku.strobe_74595();
}
