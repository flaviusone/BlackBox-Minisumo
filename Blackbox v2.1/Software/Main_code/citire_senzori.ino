/*
 Blackbox v2.1 Debug file

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



void citire_banner() {
	// for (i = 0; i < 10; i++) {
	// 	BS += digitalRead(_BS);
	// 	BD += digitalRead(_BD);
	// }
	// BS /= 10;
	// BD /= 10;
	BS = 1-digitalRead(_BS);
	BD = 1-digitalRead(_BD);
}


void citire_sharp() {
	//tu stii mai bine aici
	//I got confused
}

void citire_linie() {
	LS=0;LD=0;
	for (i = 0; i < 10; i++) {
		LS += analogRead(_LS);
		LD += analogRead(_LD);
	}
	LS /= 10;
	LD /= 10;

}