void rotiredreapta(){
  drive(viteza,-viteza);
} 
void rotirestanga(){
  drive(-viteza,viteza);
} 
void inainte(){
  drive(viteza+18,viteza);
}
void inapoi(){
  drive(-(viteza_inainte+18),-(viteza_inainte)); 
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
  inainte();
  delay(200);
  x = 6;
}
void inainte_rapid()
{
  drive(viteza_inainte+18,viteza_inainte);
}
void evitare_inapoi()
{
  inapoi();
  delay(400);
  rotiredreapta_rapid();
  delay(100);
  x = 6;
}


