


/*
my_panel.transparent = ON;
my_panel.alpha = 0; // Panel 100% transparent
while (my_panel.alpha < 100)
{
  my_panel.alpha += 20*time_step; 
  wait(1);
}
my_panel.transparent = OFF;    
*/

function resultInit(){
	
	if (abs(logoHead.y) < 50){
		total_wins += 1;
		resultWin();
	}
	else{
		total_loses += 1;	
		resultLose();
	}

	
	//curtain.flags &= ~SHOW; 
	fail.flags |= SHOW; 

}


function resultFadeIn(){

	curtain.flags |= SHOW; 

	set(curtain,TRANSLUCENT);
	curtain.alpha = 0;
	
	while(curtain.alpha < 100){
		curtain.alpha += 5 * time_step;
		wait(1);	
	}
	//reset(curtain, SHOW);
	//curtain.flags &= ~SHOW; 
	fail.flags &= ~SHOW; 


//	curtain.flags |= SHOW; 
//	fail.flags &= ~SHOW; 

}

function resultLose(){
	beep(1);
}

function resultWin(){
	beep(2);	
}
