///////////////////////////////////////////////////////////////
// 
// Autoplay
//
// by John Cabral
//
///////////////////////////////////////////////////////////////

#include <acknex.h>
#include <default.c>


ENTITY* logoHead;
ENTITY* logoBody;

var topBound = 200;
var botBound = 0;
var zSpeed = 5;
var gravity = 0.99;
var direction = 1;

function playInit(){
	logoHead = ent_create ("models\\head.mdl", vector(0,0,0), NULL); 
	logoBody = ent_create ("models\\body.mdl", vector(0,0,0), NULL); 
}

function playSetup(){
	logoHead.z = topBound;
}

function playCheckBounds(){
	if (logoHead.z < botBound) zSpeed = zSpeed * -direction;
	if (logoHead.z > topBound) zSpeed = zSpeed * -direction;

}

function playRun(){
	
	while(1){

		playCheckBounds();
		logoHead.z += zSpeed;
		wait(1);
	}
	
}

function main() {

   video_mode = 7;
	sound_vol = 100;


	level_load("models\\position.mdl");
 	vec_set(screen_color, vector(10, 10, 10));
 	
 	playInit();
 	playSetup();
	playRun();
	 	
 	camera.arc = 60;
 	camera.x = -700;
 	
	fps_max = 60;
	
	wait(3);
	

}



         
            
            
            