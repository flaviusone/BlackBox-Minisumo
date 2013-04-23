  /* Defines start */
#define md1 5
#define md2 6
#define ms2 3
#define ms1 11

#define strat_pin_0 7
#define strat_pin_1 4
#define strat_pin_2 13

#define start_pin 13  /* care e??????? */
/* o sa fie resetu defapt */

#define pin_LFR 0
#define pin_LFL 1
#define pin_LBR 2
#define pin_LBL 3
#define pin_SR 4
#define pin_SL 5

#define BB 10
#define BL 12
#define BR 9
#define BF 8



#define ledpin 10     /* care e??????? */

#define viteza 80
#define viteza_rapid 100
#define viteza_inainte 100
#define praglinie 650
#define pragsharp 250

#define valoare_delay 1000
/*--------- Defines end ---------*/
int SR,SL,LFR,LFL,LBR,LBL;
int xprec,x;


unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

void setup()
{
  modpins();           /* set req pins as I/O */
  setpins();           /* sets req pins as LOW/HIGH */
  Serial.begin(9600);  /* debug */
  //start();           /* start button */
//  delay(4000);
}
void loop()
{
/*
  inainte();
  delay(500);
  inapoi();
  delay(300);
*/

/*
  citire_linie();
  citire_sharp();
  if    ( (LFL < praglinie) || (LFR < praglinie) ) 
    evitare_inapoi(); //evitare
  else if ( (LBL < praglinie) || (LBR < praglinie) )   
    evitare_inainte();
  else
    atac();
*/



}





