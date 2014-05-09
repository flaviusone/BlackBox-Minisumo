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
#define _BS 12
#define _BD 8
#define _SHS 10
#define _SHD 9
#define _LS 0
#define _LD 1
#define _S1 7
#define _S2 4
#define _S3 2

int i,BS,BD,S1,S2,S3;
float SHS,SHD,LS=0,LD=0;
unsigned long previousMillis_SHARP = 0;
unsigned long m_lateral,m_inainte,m_rotire,m_debug,m_debug2;
char buff[20];

void setup(){

  // Setam pini ca input
  for(i = 0 ; i<19 ; i++){
    // pinMode(i,INPUT);
    pinMode(i, INPUT_PULLUP);
  }
  pinMode(_SHS, INPUT_PULLUP);
  pinMode(_SHD, INPUT_PULLUP);
  //   pinMode(_S3, INPUT_PULLUP);
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


void loop(){

  //citire Bannere
  // BS = digitalRead(_BS);
  // BD = digitalRead(_BD);
  //sprintf(buff,"BS  %d BD   %d \n",BS,BD);
  //Serial.print(buff);

  // //citire sharp lateral
  // SHS = analogRead(_SS);
  // SHD = analogRead(_SD);
  // Serial.print("SHS  ");
  // Serial.print(SHS);
  // Serial.print(" SHD ");
  // Serial.println(SHD);


  // //citire senzori linie
  // LS=0;LD=0;
  // for(i=0;i<10;i++){
  //    LS += analogRead(_LS);
  //    LD += analogRead(_LD);
  // }
  // LS /=10;LD/=10;
  // Serial.print("LS ");
  // Serial.print(LS);
  // Serial.print(" LD  ");
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
  //sprintf(buff,"_Start  %d  _Kill   %d \n",digitalRead(_Start),digitalRead(_Kill));
  int strat = strategy();
  sprintf(buff,"%d %d %d Strat=%d\n",digitalRead(_S1),digitalRead(_S2),digitalRead(_S3),strat);
  Serial.println(buff);
    //start();  
    
  delay(1000);

}
