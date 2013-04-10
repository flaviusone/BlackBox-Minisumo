void atac()
{
  x=100;
  /* urmeaza o carpeala cu delayuri */
  while(1)
  {

    /* ifuri bannere */

    /* end ifuri bannere */
    /* ifuri sharpuri */
    if ((SL>pragsharp && SR>pragsharp)  || (digitalRead(BF) == 0) ) //inainte
    {  
      x=3;
      break;
    }
    else if (SL>pragsharp && SR<pragsharp) //rotire stanga
    { 
      x=1;
      break;
    }
    else if(SL<pragsharp && SR>pragsharp) //rotire dreapta
    {
      x=2;
      break;
    }
    else //default rotire stanga
    {
      x=0; 
      //break;
    }

    if (digitalRead(BL)==0)
    {
      x=4;
      break;
    }
    else if (digitalRead(BR)==0)
    {
      x=5;
      break;
    }
    else if (digitalRead(BB)==0)
    {
      x=6;
      break;
    }

    ////////////////////////////magarie
    /*
    if ((digitalRead(BF) == 0) && (digitalRead(BR) == 0) ) //inainte
     x=3;
     else     if ((digitalRead(BF) == 0) && (digitalRead(BR) == 1) ) //ROTIRE STANGA
     x=1;
     else     if ((digitalRead(BF) == 1) && (digitalRead(BR) == 0) ) //inainte
     x=2;
     else //default rotire stanga
     x=0;
     */


    //////////////////////////


    /* end ifuri sharpuri */
    break;
  }
  switch (x){
  case 1:
    rotirestanga();
    break;
  case 2:
    rotiredreapta();
    break;
  case 3:
    inainte();
    break;
  case 4:
    rotirestanga_rapid();
   delay(100);
    break;
  case 5:
    rotiredreapta_rapid();
    delay(100);
    break;
  case 6:
    rotirestanga_rapid();
    delay(100);
    break;
  default :
    //drive(0,0);
    rotirestanga();
  }
}





