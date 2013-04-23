void atac()
{

  
  while(1)
  {

    /* ifuri sharpuri */
    if ((SL>pragsharp && SR>pragsharp)  || (digitalRead(BF) == 0) ) //inainte
    {  
      x=1;
      xprec=10;
      break;
    }
    else if (SL>pragsharp && SR<pragsharp) //rotire stanga
    { 
      //x=1;
      break;
    }
    else if(SL<pragsharp && SR>pragsharp) //rotire dreapta
    {
      //x=2;
      break;
    }
    else //default rotire stanga
    {
      x=1; 
      //break;
    }

    /* daca a fost activat BL*/
    if(xprec == 1){
      x = 4;
    }
    if(xprec == 2){
      x = 5;
    }
    if(xprec == 3){
      x = 5;
    }
    
    // if(xprec == 1){
    //   if(millis() - previousMillis1 > delay_BL)
    //   {
    //     x = 1;      /* am depasit deci return in default*/
    //     xprec = 10; /* o valoare random*/
    //     previousMillis1=millis();
    //   }
    //   else x = 4; /*RotireStangaRapid*/
    // }


    // /* daca a fost activat BR*/
    // if(xprec == 2){
    //   if(millis() - previousMillis2 > delay_BR)
    //   {
    //     x = 1;        am depasit deci return in default
    //     xprec = 10; /* o valoare random*/
    //     previousMillis2=millis();
    //   }
    //   else x = 5 ;/*RotireDreaptaRapid*/
    // }


    // /* daca a fost activat BB*/
    // if(xprec == 3){
    //   if(millis() - previousMillis3 > delay_BB)
    //   {
    //     x = 1;      /* am depasit deci return in default*/
    //     xprec = 10; /* o valoare random*/
    //     previousMillis3=millis();
    //   }
    //   else x = 5 ;/*RotireDreaptaRapid*/
    // }

    /* && xprec==10 e ca sa verific daca nu sunt deja intr-o rotire*/
    if (digitalRead(BL)==0 && xprec==10)
    {
      x=4;
      xprec=1;
      break;
    }
    else if (digitalRead(BR)==0 && xprec==10)
    {
      x=5;
      xprec=2;
      break;
    }
    else if (digitalRead(BB)==0 && xprec==10)
    {
      x=4;
      xprec=3;
      break;
    }

    /* end ifuri sharpuri */
    break;
  }
  switch (x){
    case 1:
    drive(0,0);
    //rotirestanga();
    break;
    case 2:
    rotiredreapta();
    break;
    case 3:
    inainte();
    break;
    case 4:
    rotirestanga_rapid();
    break;
    case 5:
    rotiredreapta_rapid();
    break;
    default :
    //drive(0,0);
    rotirestanga();
  }
}





