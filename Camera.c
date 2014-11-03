
ENTITY* center;


function camera_startup(){
	
	VECTOR temp;	
	center = ent_create("models\\position.mdl",vector(0,0,20),NULL);	
	
	while(1){

		vec_set(temp,center.x); 
		vec_sub(temp,camera.x);
		vec_to_angle(camera.pan,temp); 
  
		wait(1);
	}
	
}

function camera_overhead(){
	camera.x = -10;
	camera.z = 400;	
}

function camera_zoomTo(){
	
	while(1){
		camera.x -= (camera.x - (-450)) / 50;
		camera.z -= (camera.z - 10) / 50;
		wait(1);
	}

}