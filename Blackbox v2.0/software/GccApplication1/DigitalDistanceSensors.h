#ifndef _DIGITAL_DISTANCE_SENSORS_H_
#define _DIGITAL_DISTANCE_SENSORS_H_

class DigitalDistanceSensors{
	public:
	DigitalDistanceSensors();
	bool read_any();
	bool read_left();
	bool read_right();
};

#endif