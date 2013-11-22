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

// Include motor controll lib
#include <OrangutanMotors.h>
OrangutanMotors motors;
// Define pins
#define _BS 4
#define _BD 2
#define _SS 1
#define _SD 0
#define _LS 2
#define _LD 3
#define _S1 8
#define _S2 9
#define _S3 10
#define _Start A4
#define _Kill A5
int strategie;
int running=0;
void setup () {

  	modpins();   //???        /* set req pins as I/O */

	strategie = strategy(); //
	Serial.begin(9600);
	switch(strategie) {
		case 0: 
		break;
		case 1: 
		break;
		case 2: 
		break;
		case 3: 
		break;
	}

	start();
}

void loop () {
	switch(strategie) {
		case 0:
		atac_0();
		break;
		case 1: 
		break;
		case 2: 
		break;
		case 3: 
		break;
	}

	//citire_linie();
	//citire_sharp();
	//citire_banner();
	delay(100);
}