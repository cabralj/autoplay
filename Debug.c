



function debug_startup(){
		
	while(1){
		
 		screen_color.blue = 0;
 		screen_color.green = 255; // green
 		screen_color.red = 0;
 
		str_for_num(str_secs_world,	secs_world);	
		str_for_num(str_secs_game, 	secs_game);	
		str_for_num(str_total_games, 	total_games);	
		str_for_num(str_total_wins, 	total_wins);
		str_for_num(str_total_loses, 	total_loses);
		
		str_for_num(str_yTravel, 	yTravel);
		str_for_num(str_zTravel, 	zTravel);
		str_for_num(str_randomY, 	randomY);
		
		
		draw_textmode("Arial",1,20,100); 
		draw_text(state,				10,10,	vector(255,255,255));
		draw_text(str_secs_world,	10,30,	vector(255,255,255));
		draw_text(str_secs_game,	10,50,	vector(255,255,255));
		draw_text(str_total_games,	10,70,	vector(255,255,255));
		draw_text(str_total_wins,	10,90,	vector(255,255,255));
		draw_text(str_total_loses,	10,110,	vector(255,255,255));
		
		draw_text(str_yTravel,	15,130,	vector(255,255,255));
		draw_text(str_zTravel,	15,150,	vector(255,255,255));
		draw_text(str_randomY,	15,170,	vector(255,255,255));
				

				
		wait(1);

	}
}

