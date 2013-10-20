#ifndef _BANNER_SENSORS_H_
#define _BANNER_SENSORS_H_

class BannerSensors{
	public:
	BannerSensors();
	bool read_any();
	bool read_left();
	bool read_right();
};

#endif