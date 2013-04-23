void modpins()
{/* sets required pins as input/output */
  int i;
  for (i=2 ; i<14 ; i++)
  {
    pinMode(i,INPUT);
  } 
 // pinMode(ledpin,OUTPUT);
}

void setpins() 
{/* sets required pins as LOW/HIGH */
  digitalWrite(md1,LOW);
  digitalWrite(md2,LOW);
  digitalWrite(ms1,LOW);
  digitalWrite(ms2,LOW);
  digitalWrite(start_pin,LOW);  
  digitalWrite(strat_pin_0,HIGH);
  digitalWrite(strat_pin_1,HIGH);
}

void start()
{
  while(1){
    if (digitalRead(start_pin) == 1){
      //delay(4900);
      break;
    }
  }
}



