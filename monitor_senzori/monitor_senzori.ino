
float LFR,LFL,LBR,LBL,SL,SR;
int BF,BCL,BB,BCR;
void setup() 
{ 
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  Serial.begin(9600);
  delay(1000);
} 

void loop() 
{
  //  a=a+ 12343.85 * pow(analogRead(2),-1.15);
  //   b=b+ 12343.85 * pow(analogRead(3),-1.15);
  // a=a/10;
  // b=b/10;
  // c=c/5;
  // d=d/5;

  LFR = analogRead(0);   
  LFL = analogRead(1);   
  LBR = analogRead(2);   
  LBL = analogRead(3);
  SR = analogRead(4);
  SL = analogRead(5);

/*
  Serial.print("LFR ");
  Serial.print(LFR);
  Serial.print("     LFL ");
  Serial.print(LFL);
  Serial.print("           LBR ");
  Serial.print(LBR);
  Serial.print("           LBL ");
  Serial.println(LBL);
*/
 /* 
   //citire Bannere
   BB =  digitalRead(10);
   BCL = digitalRead(12);  
   BCR =   digitalRead(9);
   BF =   digitalRead(8);
   Serial.print("BCR  ");
   Serial.print(BCR);
   Serial.print("      BCL ");
   Serial.print(BCL);
   Serial.print("      BF ");
   Serial.print(BF);
   Serial.print("      BB ");
   Serial.println(BB);
  */
  
  
   //citire sharp
   Serial.print("Sharp dreapta "); 
   Serial.print(SR);
   Serial.print("   Sharp stanga "); 
   Serial.println(SL);
  




  /*  Serial.print("Senzor linie  (stanga)");
   Serial.print(analogRead(3));
   Serial.print("  |  Senzor linie (dreapta) ");
   Serial.println(analogRead(2));
   digitalWrite(9,HIGH);*/


  delay(1000);
}












