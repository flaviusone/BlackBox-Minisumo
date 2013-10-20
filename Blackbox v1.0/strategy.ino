int strategy()
{
	int pin1=0,pin0=0,pin2=0;
	for(int i=0;i<10;i++)
	{
		pin0 =  digitalRead(strat_pin_0);
		pin1 =  digitalRead(strat_pin_1);
		//pi2 =  digitalRead(strat_pin_2);
	}
	int strat = /*4 * digitalRead(strat_pin_2) +*/  2 * pin1 + 1 * pin0 ;
	return strat;
}

