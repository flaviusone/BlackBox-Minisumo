void atac()
{


  while(1)
  {
    
    /* ifuri sharpuri */ 
    if ((SL>pragsharp && SR>pragsharp)  || (digitalRead(BF) == 0) ) //inainte
    {  
      flag=1;
      if (digitalRead(BF) == 0)
      {
        x = 3; //inainte rapid
      }else x=7; //inainte normal
      xprec=10;
      break;
    }
    else if(flag == 1)
    {
      flag = 0;
      
      
      if (SL>pragsharp && SR<pragsharp) //rotire stanga
      { 
        x=1;
        millis_rotire_stanga = millis();
        break;
      }
      else if(SL<pragsharp && SR>pragsharp) //rotire dreapta
      {
        x=2;
        millis_rotire_dreapta = millis();
        break;
      }
    }


    
    if(flag == 0 && x == 1)
    {
      if(millis()-millis_rotire_stanga > delay_cautare)
      {
        x = 6;  
        break;
      }

    }
    if(flag == 0 && x == 2)
    {
      if(millis()-millis_rotire_dreapta > delay_cautare)
      {
        x = 6;
        break;
      }

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
  //drive(0,0);
    rotirestanga();
    break;
    case 2:
    rotiredreapta();
    break;
    case 3:
    inainte_rapid();
    break;
    case 4:
    rotirestanga_rapid();
    break;
    case 5:
    rotiredreapta_rapid();
    break;
    case 6:
    if(millis() - millis_inainte > delay_inainte) //a terminat de mers inainte
    {        
      if(millis() - millis_stanga > delay_stanga){
        millis_inainte = millis();
      }else
      rotirestanga();
    }else
    {
      inainte();
      millis_stanga = millis();
    }
    break;
    case 7:
    inainte();
    break;
    default :
    //drive(0,0);
    rotirestanga();
  }
}





