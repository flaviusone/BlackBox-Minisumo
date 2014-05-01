int strategy() {
	int pin1 = 0, pin2 = 0, pin3 = 0; //pin3 nefunctional ?
	for (i = 0; i < 10; i++) {
		pin1 =  digitalRead(_S1);
		pin2 =  digitalRead(_S2);
		pin3 =  digitalRead(_S3);
	}
	int strategie = 4*pin3 + 2 * pin2 + pin1 ;
	return strategie;
}

