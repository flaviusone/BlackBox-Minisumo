void rotiredreapta(){
  drive(viteza,-viteza);
} 
void rotirestanga(){
  drive(-viteza,viteza);
} 
void inainte(){
  drive(viteza_inainte+18,viteza_inainte);
}
void inapoi(){
  drive(-(viteza_inainte+58),-(viteza_inainte+40)); 
}
void rotiredreapta_rapid()
{
    drive(viteza_rapid,-viteza_rapid);
}
void rotirestanga_rapid()
{
    drive(-viteza_rapid,viteza_rapid);
}
void rotire_180 ()
{}
void evitare_inainte()
{
  drive(viteza_rapid,viteza_rapid);
  //inainte();
  delay(300);
}

void evitare_inapoi()
{
  drive(-viteza_rapid,-viteza_rapid);
  //inapoi();
  delay(300);
}


