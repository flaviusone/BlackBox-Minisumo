/*
Blackbox v2.1

PINOUT - MAPPING

BS			-	digital 4
BD			-	digital 2
LS			-	analog 2 - digital 16
LD			-	analog 3 - digital 17
SS 			-	analog 1 - digital 15
SD			-	analog 0 - digital 14
IR - Start 	-	analog 4 - digital 17
IR - Kill 	-	analog 5 - digital 18
M1.1 		-	digital 3
M1.2		-	digital 11
M2.1 		-	digital 5
M2.2 		-	digital 6
Strategy1 	-	digital 8
Strategy2 	-	digital 9
Strategy3 	-	digital 10
*/

void modpins()
{/* sets required pins as input/output */
	
	pinMode(_S1, INPUT_PULLUP);
	pinMode(_S2, INPUT_PULLUP);
	pinMode(_S3, INPUT_PULLUP);
	pinMode(_BS,INPUT);
	pinMode(_BD,INPUT);
	pinMode(_Start,INPUT);
	pinMode(_Kill,INPUT);
}

void start()
{
	while(1){
		//if ((digitalRead(_Start)==1) && (digitalRead(_Kill)==1)){
		if (digitalRead(_Start)==1){
			break;
		}
	}
}



