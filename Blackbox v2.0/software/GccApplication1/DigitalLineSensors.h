#ifndef _DIGITAL_LINE_SENSORS_H_
#define _DIGITAL_LINE_SENSORS_H_

class DigitalLineSensors{
	public:
	DigitalLineSensors();
	bool read_any();
	bool read_left();
	bool read_right();
};

#endif