///////////////////////////////////////////////////////////////
// 
// Autoplay
//
// by John Cabral
//
///////////////////////////////////////////////////////////////

#include <acknex.h>
#include <default.c>

#include <Vars.c>
#include <Strings.c>
#include <Panels.c>
#include <Timer.c>

#include <Camera.c>
#include <Play.c>

#include <Result.c>
#include <Stats.c>
#include <Reset.c>
#include <Sequence.c>
#include <Debug.c>


function main() {

   video_mode = 7;
	sound_vol = 100;

	level_load("models\\position.mdl");
 	vec_set(screen_color, vector(10, 10, 10));
 	 	
 	camera.arc = 50;
 	camera.x = -450;
 		
	fps_max = 60;
	
	wait(3);
	
	reset(curtain, SHOW);
		

}
