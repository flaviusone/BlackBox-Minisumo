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

// Include motor controll lib
#include <OrangutanMotors.h>
OrangutanMotors motors;
// Define pins
#define _BS 12
#define _BD 8
#define _SHS 10
#define _SHD 9
#define _LS 0
#define _LD 1
#define _S1 7
#define _S2 4
#define _S3 2
#define _Start 16
#define _Kill 17
#define praglinie 500
int strategie;
int viteza_inainte,viteza,viteza_rapid,val_delay;
int i,BS = 0,BD = 0,SHD=0,SHS=0,x,flag_lateral,flag_d;
float LS = 0, LD = 0;
unsigned long m_lateral,m_inainte,m_rotire,m_lat_delay,m_lat_delay_old_dr,m_lat_delay_old_st;//,m_banner_delay_st,m_banner_delay_dr,m_banner_delay_old_st,m_banner_delay_old_dr;
void setup () {
  	modpins();   //???        /* set req pins as I/O */
	start();
	strategie = strategy();
}

void loop () {	
	switch(strategie) {

		case 0:
		atac_0();
		break;
		case 2: 
		atac_2();
		break;
		case 4: 
		atac_4();
		break;
		case 6: 
		atac_6();
		break;

		case 1: 
		atac_1();
		break;
		case 3: 
		atac_3();
		break;
		case 5: 
		atac_5();
		break;
		case 7:
		atac_7();
		break;

	}
}