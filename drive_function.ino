void drive(int stanga, int dreapta){
  /*probabil o sa trebuiasca sa facem compensari manuale 
   daca robotu nu merge drept */
  if(stanga > 0) {
    analogWrite(ms1,0);
    analogWrite(ms2,stanga );
  }
  else {
    analogWrite(ms2,0);
    analogWrite(ms1,-stanga);
  }

  if(dreapta > 0) {
    analogWrite(md1,0);
    analogWrite(md2,dreapta);
  }
  else{
    analogWrite(md2,0);
    analogWrite(md1,-dreapta);
  }  
}



