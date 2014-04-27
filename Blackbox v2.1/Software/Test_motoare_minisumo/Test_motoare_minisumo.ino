/*
PIN MAPPING

M1.1    - digital 3
M1.2    - digital 11
M2.1    - digital 5
M2.2    - digital 6

*/
#include <OrangutanMotors.h>
#include <util/delay.h>
#define md1 11
#define md2 3
#define ms1 5
#define ms2 6

OrangutanMotors motors;
unsigned long prev_millis;
void setup()
{
  // pinMode(md1,OUTPUT); 
  // pinMode(md2,OUTPUT); 
  // pinMode(ms1,OUTPUT); 
  // pinMode(ms2,OUTPUT); 
  // digitalWrite(md1,LOW);
  // digitalWrite(md2,LOW);
  // digitalWrite(ms1,LOW);
  // digitalWrite(ms2,LOW);
  delay(3000);
}
void loop()
{

  // prev_millis = millis();
  // if(millis()-prev_millis < 1000){
  //   PORTD &= ~(1 << PORTD5);    // drive pin PD5 low
  //   PORTD |= (1 << PORTD6);    // drive pin PD6 high
  // }
  // prev_millis = millis();
  // if(millis()-prev_millis < 1000){
  //   PORTD |= (1 << PORTD5);    // drive pin PD5 high
  //   PORTD &= ~(1 << PORTD6);    // drive pin PD6 low
  // }
   // digitalWrite(ms1,LOW);
   // analogWrite(ms2,150);
   //  delay(1000);
   // analogWrite(ms1,150);
   // digitalWrite(ms2,HIGH);
   //  delay(1000);

   // digitalWrite(md1,1);
   // analogWrite(md2,150);
   // delay(1000);
   // digitalWrite(md1,0);
   // analogWrite(md2,150);
   // delay(1000);

  // analogWrite(ms1,100);
  // analogWrite(ms2,0);
  // delay(1000);
  //analogWrite(md1,200);
  //analogWrite(md2,0);
   //digitalWrite(md2,LOW);
   motors.setSpeeds(200,200);
     delay(1000);
//    motors.setSpeeds(-200,-200);
//     delay(1000);
}




