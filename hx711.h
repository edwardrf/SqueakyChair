#ifndef __HX711_H__
#define __HX711_H__

class Hx711 {
public:
	Hx711(uint8_t _sckpin, uint8_t _doutpin);

	bool dataReady();
	long read();
private:
	uint8_t sckpin;
	uint8_t doutpin;
	bool ready;
	long lastReadValue;
};

#endif