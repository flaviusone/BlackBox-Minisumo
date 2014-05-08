// Functia de atac de baza
void atac_4(){
	viteza_inainte = 150; 
	viteza = 150; 
	viteza_rapid = 230; 
	val_delay = 100;
	m_inainte = millis();
	m_rotire = millis();
	flag_d=1;
	while(1){

		// Check Stop
		if ((digitalRead(_Start)==0) && (digitalRead(_Kill)==0)){
			//kill motors
			while(1)
				motors.setSpeeds(0,0);
		}

		//motors.setSpeeds(100,100);
		citire_linie();
		citire_banner();
		citire_sharp();
		if(LS<praglinie && LD>praglinie){
		 	x = 11;
		 	flag_lateral=0;
		 }
		 else if(LS>praglinie && LD<praglinie){
		 	x = 10;
		 	flag_lateral=0;
		 }
		 else if(LS<praglinie && LD<praglinie){
		 	x = 1;
		 	flag_lateral=0;
		 }
		 else if(BS && BD){
		 	x = 2;
		 	flag_lateral=0;
		 }
		 else if(BS && !BD){
		 	x = 3;
		 	flag_lateral=0;
		 }
		 else if(!BS && BD){
		 	x = 4;
		 	flag_lateral=0;
		 }
		 else if(flag_lateral){
		 	if(millis() - m_lateral > val_delay)
		 	{
		 		x = 0;
		 		flag_lateral=0;
		 	}
		 }
		 else if(SHS){
		 	x = 6 ;
		 	flag_lateral = 1;
		 	m_lateral = millis();
		 	flag_d=1;
		 }
		 else if(SHD){
		 	x = 5 ;
		 	flag_lateral = 1;
		 	m_lateral = millis();
		 	flag_d=0;
		 }
		 else{
		 	if(millis()-m_inainte>300){
		 		if(millis()-m_rotire>460){
		 			m_inainte = millis();
		 			x =0;
		 			m_rotire = millis();
		 		}else{
		 			if(flag_d==1)x=5;
		 			else x=6;
		 		}
		 	}
		 	else x=0;
		 }

		 

		 switch(x){
		 	case 1:
		 		evitare_inapoi();
		 		break;
		 	case 2:
		 		inainte();
		 		break;
		 	case 3:
		 		rotirestanga();
		 		break;
	 		case 4:
	 			rotiredreapta();
	 			break;	
	 		case 5:
	 			rotiredreapta_rapid();
	 			break;
	 		case 6:
	 			rotirestanga_rapid();
	 			break;
	 		case 10:
		 		evitare_inapoi_arc_stanga();
		 		break;
	 		case 11:
	 			evitare_inapoi_arc_dreapta();
	 			break;
		 	default:
		 			motors.setSpeeds(130,130);
		 			//motors.setSpeeds(255,10);
					//motors.setSpeeds(-200,200);		 			
		 		//motors.setSpeeds(-150,150);
		 		//motors.setSpeeds(0,0);
		 }
	}
}