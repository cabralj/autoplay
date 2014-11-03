


function statsInit(){

			
	while(str_cmp(state,"STATS")){
		
		draw_textmode("Arial",1,48,100); 
		
		draw_text("Games",			10,	10,	vector(255,255,255));
		draw_text(str_total_games,	200,	10,	vector(255,255,255));
		
		draw_text("Wins",				10,	100,	vector(255,255,255));
		draw_text(str_total_wins,	200, 	100,	vector(255,255,255));
		
		draw_text("Loses",			10,	150,	vector(255,255,255));
		draw_text(str_total_loses,	200,	150,	vector(255,255,255));

		
		draw_textmode("Arial",1,20,100); 
		draw_text("2 Days 10 Hours 25 Minutes and 25 seconds remaining",	10,	450,	vector(255,255,255));
				
		wait(1);
		
	}
	
	
}