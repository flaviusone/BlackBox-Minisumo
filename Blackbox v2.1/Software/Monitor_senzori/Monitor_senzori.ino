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
#define _SHS A1
#define _SHD A0
#define _LS 2
#define _LD 3
#define _S1 8
#define _S2 9
#define _S3 10
#define _Start A4
#define _Kill A5

int i,BS,BD,S1,S2,S3;
float SHS,SHD,LS=0,LD=0;
unsigned long previousMillis_SHARP = 0;
unsigned long m_lateral,m_inainte,m_rotire,m_debug,m_debug2;
char buff[20];

void setup(){

  // Setam pini ca input
  for(i = 0 ; i<19 ; i++)
    pinMode(i,INPUT);
  // pinMode(_S1, INPUT_PULLUP);
  //   pinMode(_S2, INPUT_PULLUP);
  //   pinMode(_S3, INPUT_PULLUP);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  Serial.begin(9600);
}
void citire_sharp() {
  SHS = 0;
  SHD = 0;
  for(i=0;i<6;i++){
    SHS += digitalRead(_SHS);
    SHD += digitalRead(_SHD);
  }
  if(SHS>3) 
    SHS=0;
  else
    SHS=1;
  if(SHD>3)
    SHD=0;
  else
    SHD=1;
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
void loop(){

  //citire Bannere
  // BS = digitalRead(_BS);
  // BD = digitalRead(_BD);
  //sprintf(buff,"BS 	%d BD  	%d \n",BS,BD);
  //Serial.print(buff);

  // //citire sharp lateral
  // SHS = analogRead(_SS);
  // SHD = analogRead(_SD);
  // Serial.print("SHS	");
  // Serial.print(SHS);
  // Serial.print("	SHD	");
  // Serial.println(SHD);


  // //citire senzori linie
  // LS=0;LD=0;
  // for(i=0;i<10;i++){
  //    LS += analogRead(_LS);
  //    LD += analogRead(_LD);
  // }
  // LS /=10;LD/=10;
  // Serial.print("LS	");
  // Serial.print(LS);
  // Serial.print("	LD	");
  // Serial.println(LD);
  // SHS = digitalRead(_SHS);
  // SHD = digitalRead(_SHD);
  // Serial.print("SHS  ");
  // Serial.print(SHS);
  // Serial.print(" SHD ");
  // Serial.println(SHD);


  // BS = digitalRead(_BS);
  // BD = digitalRead(_BD);
  // Serial.print("BS  ");
  // Serial.print(BS);
  // Serial.print(" BD ");
  // Serial.println(BD);

  // m_debug = micros();
  // citire_sharp();
  // m_debug2 = micros()-m_debug;
  // Serial.print("Time: ");
  // Serial.println(m_debug2);


  //   //citire switch strategie
  //   for(i=0;i<10;i++){
  //    S1 = digitalRead(_S1);
  //    S2 = digitalRead(_S2);	
  //    S3 = digitalRead(_S3);
  // }
    sprintf(buff,"_Start  %d  _Kill   %d \n",digitalRead(_Start),digitalRead(_Kill));
    Serial.print(buff);
    start();  
    
  // delay(300);

}


