int strategy() {
	int pin1 = 0, pin2 = 0, pin3 = 0; //pin3 nefunctional ?
	for (int i = 0; i < 10; i++) {
		pin1 =  digitalRead(strategie_pin1);
		pin2 =  digitalRead(strategie_pin2);
		//pin3 =  digitalRead(strategie_pin3);
	}
	int strategie = 2 * pin2 + pin1 ;
	return strategie;
}

