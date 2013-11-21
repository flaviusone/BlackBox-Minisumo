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
#define _BS 4
#define _BD 2
#define _SS 1
#define _SD 2
int i,BS,BD;
float SHS,SHD;
char buff[20];

void setup(){

	// Setam pini ca input
	for(i = 0 ; i<19 ; i++)
		pinMode(i,INPUT);

    Serial.begin(9600);
}
 
void loop(){
  
   //citire Bannere
   BS = digitalRead(_BS);
   BD = digitalRead(_BD);
   //sprintf(buff,"BS 	%d BD  	%d \n",BS,BD);
   //Serial.print(buff);

   //citire sharp lateral
   SHS = analogRead(_SS);
   SHD = analogRead(_SD);
   Serial.println(SHS);
   Serial.println(SHD);
   //sprintf(buff,"SHS 	%f SHD  	%f \n",SHS,SHD);
   //Serial.print(buff);

   delay(1000);

}

