// the sensor communicates using SPI, so include the library:
#include <SPI.h>
#include "hx711.h"

Hx711 s1(10, 11);
Hx711 s2(12, 13);

void setup() {
  Serial.begin(115200);
}

void loop() {
  long v1, v2;
  if(s1.dataReady()) v1 = s1.read();
  if(s2.dataReady()) v2 = s2.read();
  
  Serial.print(v1);
  Serial.print("\t");
  Serial.print(v2);
  Serial.print("\t");
  delay(100);
}
