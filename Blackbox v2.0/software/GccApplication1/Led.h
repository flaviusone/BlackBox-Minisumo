#ifndef _LED_H_
#define _LED_H_

class Led{
	public:
	Led();	
	void on();
	void off();
	void toggle();
	bool get_status();
};

#endif