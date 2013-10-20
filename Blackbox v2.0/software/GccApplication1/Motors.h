#ifndef _MOTORS_H_
#define _MOTORS_H_

class Motors{
	private:
	void pwm_left(int16_t);
	void pwm_right(int16_t);
	
	public:
	Motors();
	void go_fwd();
};
#endif