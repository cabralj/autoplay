
BMAP* blackImg 	= "sprites\\peaBlack.tga";
BMAP* errorImg 	= "sprites\\error.tga";
BMAP* replayImg 	= "sprites\\replay.bmp";

PANEL* bkg {bmap=blackImg; layer=2; flags=refresh,d3d,visible;}
PANEL* errorPanel { bmap=errorImg; pos_x = 220; pos_y = 120; layer=9; flags=refresh,d3d,visible;}
PANEL* fadePanel { bmap=blackImg; pos_x = 0; pos_y = 0; layer=20; flags=refresh,d3d;}
PANEL* replay {bmap=replayImg; layer=10; flags=refresh,d3d,overlay;}

ENTITY* logoHoop1 { type = "sprites\\hoop1.tga"; x = 200; y = 0; z = 0; layer = 7; }
ENTITY* logoHoop2 { type = "sprites\\hoop2.tga"; x = 300; y = 0; z = 0; layer = 6; }
ENTITY* logoHoop3 { type = "sprites\\hoop3.tga"; x = 50; y = 0; z = 0; layer = 5; }
ENTITY* logoHoop4 { type = "sprites\\hoop4.tga"; x = 10; y = 0; z = 0; layer = 4; }

ENTITY* logoBody { type = "models\\body.mdl"; x = 300; y = 0; z = 10; layer = 9;}
ENTITY* logoHead { type = "models\\head.mdl"; x = 300; y = 0; z = 10; layer = 9;}

SOUND* ding  = "sounds\\bell.wav";
SOUND* winner = "sounds\\rainbow.wav";
SOUND* loser = "sounds\\buzz.wav";

var leftBound = 150;
var rightBound = -150;
var topBound = 150;
var bottomBound = 10;
var gravity = 1;
var yTravel;
var zTravel;
var yInc;
var zInc;
var hitSound;
var resultSound;
var sndFreq = 20;
var countDown = 100;
var logoGame = 0;
var lastWinner = 0;
var lastLogoHeadY;
var lastYTravel;
var distanceToGoal;


function scaleWinnerCircle(ent,num);

function initLogoGame(){
	//exclusive_global;
	initLogoSetup();
	if (lastWinner < 1){
		wait(200);
		distanceToGoal = .001;
		fps_max = 120;
	}
	else{
		wait(1);
		replay.visible = on;
		distanceToGoal = .01;
		fps_max = 15;
	}
	while(abs(yInc) > distanceToGoal && abs(zInc) > distanceToGoal){
		animBounceBody();
		//lookAtTarget();
		checkLogoBounds();
		wait(1);
	}
	checkWinner();
	fps_max = 120;
}


function initLogoSetup(){
	//exclusive_global;
	sndFreq = 20;
	camera.arc = 60;
	logoHead.skin = 1;
	errorPanel.visible = off;
	fadePanel.visible = off;
	
	logoHead.z = 150;
	//logoHead.y = 150;
	//yTravel = 60;
	
	if (lastWinner < 1){
		logoHead.y = random(300) - 150;
		yTravel = random(300) - 150;
		lastLogoHeadY = logoHead.y;
		lastYTravel = yTravel;
	
	}
	else{
		logoHead.y = lastLogoHeadY;
		yTravel = lastYTravel;
	}

	
	if (yTravel > 0){ logoBody.y = -500;}
	else{logoBody.y = 500;}
	
	zTravel = -10;	
	yInc = yTravel / 20;
	zInc = zTravel / 20;
	logoHead.visible = on;
	logoBody.visible = on;
}

function animBounceBody(){
	yInc = yInc * .98;
	zInc = zInc * .98;
	zInc = zInc - gravity;
	logoHead.y = logoHead.y + yInc;
	logoHead.z = logoHead.z + zInc;
	logoBody.y -= (logoBody.y - logoHead.y) / 5;

	//logoPosi.z = logoBody.y * 2;
		
	logoHead.pan += yInc * 5;
	logoHead.roll = yInc;
	logoHead.tilt = yInc;
}

/*
function lookAtTarget(){
	vec_set(temp,logoPosi.x); 
	vec_sub(temp,logoHead.x);
	vec_to_angle(logoHead.pan,temp);
}*/


function checkLogoBounds(){
	if (logoHead.y < rightBound) {
		logoHead.y = rightBound;
		if (lastWinner < 1) { playHitSound();}
		yInc *= -1;
	} 	
	if (logoHead.y > leftBound) {
		logoHead.y = leftBound;
		if (lastWinner < 1) { playHitSound();}
		yInc *= -1;
	}		
	if (logoHead.z < bottomBound) {
		logoHead.z = bottomBound;
		if (lastWinner < 1) { playHitSound();}
		zInc *= -1;
	}
}

function playHitSound(){
	if (abs(yInc) > 1 || abs(zInc) > 1){
		stop_sound(hitSound);

		play_sound (ding, 50);
		hitSound = result;
		//sndFreq = random(5) + 200;
		sndFreq = 2000;
		snd_tune(hitSound, 50, 2000,0);
	}
}

function checkWinner(){
	logoGame = 1;
	if (abs(logoHead.y) > 25){
		logoHead.skin = 2;
		showErrorPanel();
		play_sound (loser, 100);
		resultSound = result;
		tune_sound (resultSound, 100, 150);
		startCountDown(100);
	}
	else{
		logoHead.skin = 3;
		if (lastWinner < 1){
			lastWinner = 1;
			showWinnerPanel();
			play_sound (winner,100);
			resultSound = result;
			tune_sound (resultSound, 100, 200);
			startCountDown(200);
		}
		else{
			lastWinner = 0;
			startCountDown(1);
		}
	}
	
}

function showWinnerPanel(){
	logoHead.y = 0;
	logoHead.z = 10;
	logoBody.y = 0;
	scaleWinnerCircle(logoHoop1,1);
	scaleWinnerCircle(logoHoop2,2);
	scaleWinnerCircle(logoHoop3,3);
	scaleWinnerCircle(logoHoop4,4);
	
	while(logoGame == 1){
		logoHead.pan += 20;
		logoHead.pan %= 360;
		logoBody.pan += 20;
		logoBody.pan %= 360;
		wait(1);
	}
	
	/*
	while(camera.arc < 120){
		if(camera.arc * 1.01 <= 120){
			camera.arc *= 1.01;
		}
		else{
			camera.arc = 120;
		}
		wait(1);		
	}*/

}



function startCountDown(delay){
	waitt(delay);
	if(lastWinner < 1){
		fadePanel.transparent = on;
		fadePanel.alpha = 0;
		fadePanel.visible = on;
		while(fadePanel.alpha < 100){
			fadePanel.alpha += 1;
			wait(1);
		}
	}
	replay.visible = off;
	logoGame = 0;
	wait(2);
	initLogoGame();
}




function showErrorPanel(){
	errorPanel.transparent = on;
	errorPanel.alpha = 25;
	errorPanel.visible = on;
}


function scaleWinnerCircle(ent,num){
	my = ent;
	my.visible = on;
	my.scale_x = ((1 - .05) / 4) * num;
	my.scale_y = ((1 - .05) / 4) * num;
	
	while(logoGame == 1){
		
		if (my.scale_x > 1){
			my.skill1 = 100;
			my.scale_x = .05;
			my.scale_y = .05;
		}
		else{
			my.skill1 -= 1;
			my.alpha = my.skill1;
			my.scale_x += .01;
			my.scale_y += .01;
		}
		wait(1);
	}
	my.visible = off;
	my.scale_x = 1;
	my.scale_y = 1;
}



