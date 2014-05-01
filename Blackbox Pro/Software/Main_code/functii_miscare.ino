void rotiredreapta(){
  motors.setSpeeds(viteza,-viteza);
} 
void rotirestanga(){
  motors.setSpeeds(-viteza,viteza);
} 

void rotiredreapta_arc(){
  motors.setSpeeds(viteza,0);
} 
void rotirestanga_arc(){
  motors.setSpeeds(0,viteza);
} 

void inainte(){
  motors.setSpeeds(viteza,viteza);
}
void inapoi(){
  //motors.setSpeeds(-(viteza_inainte),-(viteza_inainte)); 
  motors.setSpeeds(-250,-250); 
}
void rotiredreapta_rapid()
{
    motors.setSpeeds(viteza_rapid,-viteza_rapid);
}
void rotirestanga_rapid()
{
    motors.setSpeeds(-viteza_rapid,viteza_rapid);
}

void inainte_rapid()
{
  motors.setSpeeds(viteza_inainte,viteza_inainte);
}
void evitare_inapoi()
{
  inapoi();
  delay(100);
  motors.setSpeeds(-150,-150+10); 
  delay(100);
  //rotiredreapta_rapid();
  //delay(100);
  //x = 6;
}
void evitare_inapoi_arc_stanga()
{
  motors.setSpeeds(-250,0); 
  delay(100);
  motors.setSpeeds(-150,-150+10); 
  delay(100);
  //rotiredreapta_rapid();
  //delay(100);
  //x = 6;
}
void evitare_inapoi_arc_dreapta()
{
  motors.setSpeeds(0,-250); 
  delay(100);
  motors.setSpeeds(-150,-150+10); 
  delay(200);
  //rotiredreapta_rapid();
  //delay(100);
  //x = 6;
}

