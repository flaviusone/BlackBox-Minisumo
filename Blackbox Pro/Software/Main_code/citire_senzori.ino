/*
 Blackbox vPro Debug file
 
 PINOUT - MAPPING
 
 BS			-	digital 12
 BD			-	digital 8
 LS			-	analog 0 
 LD			-	analog 1 
 SS 		-	digital 10
 SD			-	digital 9
 IR - Start 	-	analog 2 - digital 16
 IR - Kill 	-	analog 3 - digital 17
 M1.1 		-	digital 3
 M1.2		-	digital 11
 M2.1 		-	digital 5
 M2.2 		-	digital 6
 Strategy1 	-	digital 7
 Strategy2 	-	digital 4
 Strategy3 	-	digital 2
 */



void citire_banner() {
	// for (i = 0; i < 10; i++) {
	// 	BS += digitalRead(_BS);
	// 	BD += digitalRead(_BD);
	// }
	// BS /= 10;
	// BD /= 10;
	BS = digitalRead(_BS);
	BD = digitalRead(_BD);
}


void citire_sharp() {
	SHS = 0;
	SHD = 0;
	for(i=0;i<12;i++){
		SHS += digitalRead(_SHS);
		SHD += digitalRead(_SHD);
	}
	if(SHS>6) 
		SHS=0;
	else
		SHS=1;
	if(SHD>6)
		SHD=0;
	else
		SHD=1;
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
