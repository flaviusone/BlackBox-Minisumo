int strategy()
{
	int strat = 4 * digitalRead(strat_pin_0) + 2 * digitalRead(strat_pin_1) 
	+ 1 * digitalRead(strat_pin_2);
	return strat;
}

