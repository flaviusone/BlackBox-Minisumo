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
 
void modpins()
{/* sets required pins as input/output */
	
	pinMode(_S1, INPUT_PULLUP);
	pinMode(_S2, INPUT_PULLUP);
	pinMode(_S3, INPUT_PULLUP);
	pinMode(_BS,INPUT);
	pinMode(_BD,INPUT);
	pinMode(_Start,INPUT);
	pinMode(_Kill,INPUT);
	pinMode(_SHD, INPUT_PULLUP);
  	pinMode(_SHS, INPUT_PULLUP);
}

void start()
{
	while(1){
		// Serial.println(digitalRead(_Start));
		// delay(100);
		if ((digitalRead(_Start)==1) && (digitalRead(_Kill)==1)){
		// if (digitalRead(_Start)==1){
			break;
		}
	}
}



