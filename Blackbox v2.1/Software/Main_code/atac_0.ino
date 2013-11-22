void atac_0(){
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
		if(LS<praglinie || LD<praglinie)
		 {
		 	motors.setSpeeds(-100,-100);
		 	delay(300);
		 	motors.setSpeeds(-100,100);
		 	delay(500);
		 }
		 if(BS && BD)
		 	motors.setSpeeds(200,200);
		 else if(BS && !BD)
		 	motors.setSpeeds(100,-100);
		 else if(!BS && BD)
		 	motors.setSpeeds(-100,100);
		 else
		 	motors.setSpeeds(0,0);
	}
}