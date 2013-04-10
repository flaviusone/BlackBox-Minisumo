#define md1 5
#define md2 6
#define ms1 3
#define ms2 11
void setup()
{
  pinMode(md1,OUTPUT); 
  pinMode(md2,OUTPUT); 
  pinMode(ms1,OUTPUT); 
  pinMode(ms2,OUTPUT); 
  digitalWrite(md1,LOW);
  digitalWrite(md2,LOW);
  digitalWrite(ms1,LOW);
  digitalWrite(ms2,LOW);
  delay(1000);

}
void loop()
{
  analogWrite(ms1,0);
  analogWrite(ms2,200);
  analogWrite(md1,200);
  analogWrite(md2,0);
  //  digitalWrite(md2,LOW);
}




