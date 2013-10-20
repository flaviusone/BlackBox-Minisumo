#define repetari 10
unsigned long previousMillis_SHARP = 0;
void citire_linie()
{
  int i;
  LFR=0;  
  LFL=0;  
  LBR=0;  
  LBL=0; 
  for ( i = 0 ; i < repetari ; i++ )
  {
    LFR += analogRead(pin_LFL);
    LFL += analogRead(pin_LFR);
    LBR += analogRead(pin_LBL);
    LBL += analogRead(pin_LBR);
  }
  LFL = LFL / repetari;
  LFR = LFR / repetari;
  LBR = LBR / repetari;
  LBL = LBL / repetari;
}//citire_linie()

void citire_sharp()
{
  if (millis() - previousMillis_SHARP > 41 ){
    SL = analogRead(pin_SL);
    SR = analogRead(pin_SR);
  }
}//citire_sharp();
void citire_banner()
{
// posibil sa nu fie nevoie
}//citire_banner()


