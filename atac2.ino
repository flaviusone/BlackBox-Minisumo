void atac2()
{

  
  while(1)
  {

    /* ifuri sharpuri */
  if ((SL>pragsharp && SR>pragsharp)  || (digitalRead(BF) == 0) ) //inainte
  {  
    flag=1;
    x=3;
    xprec=10;
    break;
  }
  else if(flag == 1)
  {
    flag = 0;
      if (SL>pragsharp && SR<pragsharp) //rotire stanga
      { 
        x=1;
        break;
      }
    else if(SL<pragsharp && SR>pragsharp) //rotire dreapta
    {
      x=2;
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
  break;
  case 5:
  rotiredreapta_rapid();
  break;
  default :
    //drive(0,0);
  rotirestanga();
}
}





