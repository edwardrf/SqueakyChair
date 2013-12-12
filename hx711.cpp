#include <Arduino.h>
#include "hx711.h"

Hx711::Hx711(uint8_t _sckpin, uint8_t _doutpin):
	sckpin(_sckpin), doutpin(_doutpin), ready(false), lastReadValue(0)
{
	pinMode(sckpin, OUTPUT);
	pinMode(doutpin, INPUT);
	digitalWrite(sckpin, LOW);
}

bool Hx711::dataReady(){
	if(!ready) ready = !digitalRead(doutpin);
	return ready;
}

long Hx711::read(){
	if(ready){
		byte data[3];

		while (digitalRead(doutpin));

		for (byte j = 0; j < 3; j++){
			for (byte i = 0; i < 8; i++){
				digitalWrite(sckpin, HIGH);
				bitWrite(data[2 - j], 7 - i, digitalRead(doutpin));
				digitalWrite(sckpin, LOW);
			}
		}

		// The 25th cycle to indicate we still want to read channel A with 128gain 
		digitalWrite(sckpin, HIGH);
		digitalWrite(sckpin, LOW);

		lastReadValue = ((((long) data[2] << 16) | ((long) data[1] << 8) | (long) data[0]) << 8) / 256;
		ready = false;
	}
	return lastReadValue;
}
