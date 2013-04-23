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

/*
#define viteza 80
#define viteza_rapid 100
#define viteza_inainte 100
Old values before 
*/

#define praglinie 650
#define pragsharp 250

#define valoare_delay 1000
/*--------- Defines end ---------*/
int SR,SL,LFR,LFL,LBR,LBL;
int xprec,x,strat;
int viteza,viteza_inainte,viteza_rapid;
int delay_BL,delay_BR,delay_BB;

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
int stop=0;
void setup()
{
  modpins();           /* set req pins as I/O */
  setpins();           /* sets req pins as LOW/HIGH */
  strat = strategy();
  switch(strat){
    case 0:
    viteza = 100;
    viteza_rapid = 120;
    viteza_inainte = 120;
    break;
    case 1:
    viteza = 120;
    viteza_rapid = 140;
    viteza_inainte = 140;
    break;
    case 2:
    viteza = 140;
    viteza_rapid = 160;
    viteza_inainte = 160;
    break;
    case 3:
    viteza = 160;
    viteza_rapid = 180;
    viteza_inainte =180;
    break;
  }
  Serial.begin(9600);  /* debug */
  start();           /* start button */
  //  delay(4000);
  
}
void loop()
{


/* Main Code
  citire_linie();
  citire_sharp();
  if    ( (LFL < praglinie) || (LFR < praglinie) ) 
    evitare_inapoi(); //evitare
  else if ( (LBL < praglinie) || (LBR < praglinie) )   
    evitare_inainte();
  else
    atac();
*/

/* Debug Code*/
  citire_linie();
  citire_sharp();
  if    ( (LFL < praglinie) || (LFR < praglinie) ) {
    evitare_inapoi(); //evitare
    drive(0,0);
    stop=1;
  }
  else if ( (LBL < praglinie) || (LBR < praglinie) )   {
    evitare_inainte();
    drive(0,0);
    stop=1;
  }
  else if (stop==0)
    inainte();


}





