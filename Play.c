

ENTITY* logoHead;
ENTITY* logoBody;

var leftBound 		= 200;
var rightBound 	= -200;
var topBound 		= 200;
var bottomBound 	= 10;

var yInc;
var zInc;

var yTravel;
var zTravel;

var gravity = 0.8;
var randomY = 1;

var distanceToTarget = 0;

function play_startup(){
	
	logoHead = ent_create ("models\\head.mdl", vector(0,0,0), NULL); 
	logoBody = ent_create ("models\\body.mdl", vector(0,0,0), NULL); 
	//ent_create("sprites\\black.tga",vector(0,0,0),NULL);
	
}


function playShowGetReady(){
	
//	set(curtain, SHOW);
	total_games += 1;
	while(str_cmp(state,"READY")){
		draw_textmode("Arial",1,64,100); 
		draw_text("Ready",	10,10,	vector(255,255,255));
		wait(1);
		
	}	
}


function playCheckBounds(){
	if (logoHead.y < rightBound) {
		logoHead.y = rightBound;
		//if (lastWinner < 1) { playHitSound();}
		yInc *= -1;
	} 	
	if (logoHead.y > leftBound) {
		logoHead.y = leftBound;
		//if (lastWinner < 1) { playHitSound();}
		yInc *= -1;
	}		
	if (logoHead.z < bottomBound) {
		logoHead.z = bottomBound;
		//if (lastWinner < 1) { playHitSound();}
		zInc *= -1;
	}
}

function playInit(){
	

	reset(curtain, SHOW);
	randomY = random(800)-400;
	
	logoHead.y = randomY;
	logoHead.z = 300;
		
	yTravel = 400;
	zTravel = -400;
		
	yInc = yTravel / 50;
	zInc = zTravel / 50;
	
	while(str_cmp(state,"PLAY")){
			
		yInc = yInc * .99;
		zInc = zInc * .99;
		
		zInc = zInc - gravity;
		logoHead.y = logoHead.y + yInc;
		logoHead.z = logoHead.z + zInc;
	 	logoBody.y -= (logoBody.y - logoHead.y) / 2;
	 	
	 	//camera.z = logoHead.z;
	 	
	
		//logoPosi.z = logoBody.y * 2;
			
		logoHead.pan += yInc * 5;
		logoHead.roll = yInc;
		logoHead.tilt = yInc;

		logoBody.pan += -yInc * 3;
				
		playCheckBounds();
				
		wait(1);
	
	}	
	
}


