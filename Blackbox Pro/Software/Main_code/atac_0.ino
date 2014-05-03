void atac_0(){
	viteza_inainte = 255; 
	viteza = 200; 
	viteza_rapid = 255; 
	val_delay = 100;
	flag_d=1;
	m_lat_delay_old_st = 0;
	m_lat_delay_old_dr = 0;
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
		// citire_sharp();

		if(LS<praglinie && LD>praglinie){
		 	x = 11;
		 	flag_lateral=0;
		 	m_lat_delay_old_st = micros();
		 	m_lat_delay_old_dr = micros();
		 }
		 else if(LS>praglinie && LD<praglinie){
		 	x = 10;
		 	flag_lateral=0;
		 	m_lat_delay_old_st = micros();
		 	m_lat_delay_old_dr = micros();
		 }
		 else if(LS<praglinie && LD<praglinie){
		 	x = 1;
		 	flag_lateral=0;
		 	m_lat_delay_old_st = micros();
		 	m_lat_delay_old_dr = micros();
		 }
		 else if(BS && BD){
		 	x = 2;
		 	flag_lateral=0;
		 	m_lat_delay_old_st = micros();
		 	m_lat_delay_old_dr = micros();
		 }
		 else if(BS && !BD){
		 	x = 3;
		 	flag_lateral=0;
		 	m_lat_delay_old_st = micros();
		 	m_lat_delay_old_dr = micros();
		 }
		 else if(!BS && BD){
		 	x = 4;
		 	flag_lateral=0;
		 	m_lat_delay_old_st = micros();
		 	m_lat_delay_old_dr = micros();
		 }
		 else if(flag_lateral){
		 	if(millis() - m_lateral > val_delay)
		 	{
		 		x = 0;
		 		flag_lateral=0;
		 		m_lat_delay_old_st = micros();
		 		m_lat_delay_old_dr = micros();
		 	}
		 }
		 else if(SHS){
		 	if(micros()-m_lat_delay_old_st>15000){
		 		x = 6;
		 		flag_lateral = 1;
		 		m_lateral = millis();
		 		flag_d=1;
		 	}
		 }
		 else if(SHD){
		 	if(micros()-m_lat_delay_old_dr>15000){
		 		x = 5 ;
			 	flag_lateral = 1;
			 	m_lateral = millis();
			 	flag_d=0;
		 	}
		 }
		 else{
		 	m_lat_delay_old_st = micros();
		 	m_lat_delay_old_dr = micros();
		 	x = 0 	;
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
	 		case 10:
		 		evitare_inapoi_arc_stanga();
		 		break;
	 		case 11:
	 			evitare_inapoi_arc_dreapta();
	 			break;
	 		case 5:
	 			rotiredreapta_rapid();
	 			break;
	 		case 6:
	 			rotirestanga_rapid();
	 			break;
		 	default:
	 		if(flag_d==1)
		 			motors.setSpeeds(10,255);
		 			// motors.setSpeeds(0,0);
		 		else
		 			motors.setSpeeds(255,10);
		 			// motors.setSpeeds(0,0);
			break;		 		
		 }
	}
}