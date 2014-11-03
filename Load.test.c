///////////////////////////////////////////////////////////////
// 
// Autoplay
//
// by John Cabral
//
///////////////////////////////////////////////////////////////


#include <acknex.h>
#include <default.c>

ENTITY* logoBody { type = <body.mdl>; x = 0; y = 0; z = 10; layer = 9; flags = SHOW;}
ENTITY* logoHead { type = <head.mdl>; x = 0; y = 0; z = 10; layer = 9; flags = SHOW;}

function main() {

   video_mode = 7;
	sound_vol = 100;


	level_load("models\\position.mdl");
 	vec_set(screen_color, vector(10, 10, 10));


	
	wait(3);
	

}
