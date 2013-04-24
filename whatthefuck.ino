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



/*
#define viteza 80
#define viteza_rapid 100
#define viteza_inainte 100
Old values before 
*/
#define ajustare 40
#define praglinie 650
#define pragsharp 275

#define valoare_delay 1000
/*--------- Defines end ---------*/
int SR,SL,LFR,LFL,LBR,LBL;
int xprec,x,strat;
int viteza,viteza_inainte,viteza_rapid;
int delay_BL,delay_BR,delay_BB,delay_inainte,delay_stanga,delay_cautare;

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long millis_inainte = 0;
unsigned long millis_stanga = 0;
unsigned long millis_rotire_stanga = 0;
unsigned long millis_rotire_dreapta = 0;
unsigned long millis_linie = 0;
int stop=0,flag=0;
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
    
    delay_inainte = 400;
    delay_stanga = 300;
    delay_cautare = 500;

    //debug
    /*
    viteza = 50;
    viteza_rapid = 70;
    viteza_inainte = 70;
    */
    //debug
    break;
    case 1:
    viteza = 100;
    viteza_rapid = 120;
    viteza_inainte = 120;
    
    delay_inainte = 400;
    delay_stanga = 250;
    delay_cautare = 500;
    break;
    case 2:
    viteza = 120;
    viteza_rapid = 140;
    viteza_inainte = 140;

    delay_inainte = 300;
    delay_stanga = 250;
    delay_cautare = 500;
    break;
    case 3:
    viteza = 140;
    viteza_rapid = 160;
    viteza_inainte =160;

    delay_inainte = 300;
    delay_stanga = 250;
    delay_cautare = 500;
    break;
  }
  x=6;
  xprec=10;
  Serial.begin(9600);  /* debug */
  start();           /* start button */
  //Serial.println(strat);
  
}
void loop()
{


/* Main Code */
  citire_linie();
  citire_sharp();
  if (LFL < praglinie) {
    drive(-viteza_inainte,-viteza_inainte-50);
    delay(400);
    millis_inainte+=400;

  }
  else if (LFR < praglinie){
    drive(-viteza_inainte-50,-viteza_inainte);
    delay(400);
    millis_inainte+=400;

  }
  else if ( (LBL < praglinie) || (LBR < praglinie) )   
    evitare_inainte();
  else if (strat == 0)
    atac();
  else if (strat == 1) 
    atac2();
  else atac();



/*
drive(0,0);

if (digitalRead(BL)==0 && stop==0){
  rotirestanga_rapid();
  delay(delay_BB);
  stop =  1;
}

drive(0,0);
*/
/* Debug Code*/
/*  citire_linie();
  citire_sharp();
  if    ( (LFL < praglinie) || (LFR < praglinie) ) {
    evitare_inapoi(); //evitare
  
    stop=1;
  }
  else if ( (LBL < praglinie) || (LBR < praglinie) )   {
    evitare_inainte();
    drive(0,0);
    stop=1;
  }
  else if (stop==0)
    inainte();
*/

}





