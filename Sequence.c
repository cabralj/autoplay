



function sequence_startup(){
	
	var t = 0;
	while(1){
		
		t = integer(secs_game);
		
		if (t == 0 && str_cmp(state, "RESET")){

			// READY	
			str_cpy(state,"READY");
			playShowGetReady();

		}
		else if (t == 4 && str_cmp(state,"READY")){
			
			// PLAY
			str_cpy(state,"PLAY");
			playInit();	
			
		}
		else if (t == 12 && str_cmp(state,"PLAY")){
			
			// RESULTS
			str_cpy(state,"RESULT");
			resultInit();
			
		}
		else if (t == 14 && str_cmp(state,"RESULT")){
			
			// STATS
			str_cpy(state,"RESULT_FADEIN");
			resultFadeIn();

		}
		else if (t == 15 && str_cmp(state,"RESULT_FADEIN")){
			
			// STATS
			str_cpy(state,"STATS");
			statsInit();
			
		}	
		else if (t == 20 && str_cmp(state, "STATS")){
			
			// RESET
			str_cpy(state,"RESET");
			
		}
		
		wait(1);
	
	}	
	
}