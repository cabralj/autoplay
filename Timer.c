

STRING* str_time_remaining = "yo";
STRING* str_time_days = 0;
STRING* str_time_hours = 0;
STRING* str_time_minutes = 0;
STRING* str_time_seconds = 0;




var secs_world = 0;
var secs_game 	= 0;
var tick = 0;


var time = 604800;


var days = 0;

var daySecs = 86400;

var dayFactor = 0;


var hours = 0;

var hourSecs = 3600;

var hourFactor = 0;


var minutes = 0;

var minuteSecs = 60;

var minuteFactor = 0;



var seconds = 0;


function timeToDate(){
	
	time = 604800 - integer(secs_world);

	// DAYS
	var dayFactor = time / daySecs;

	if (dayFactor > 0 ){
	
		days = integer(dayFactor);	
	
		time -= days * daySecs;

	}


	
	// HOURS

	hourFactor = time / hourSecs;

	if (hourFactor > 0 ){
	
		hours = integer(hourFactor);	
	
		time -= hours * hourSecs;

	}


	
	// MINUTES

	minuteFactor = time / minuteSecs;

	if (minuteFactor > 0 ){
	
		minutes = integer(minuteFactor);	
	
		time -= minutes * minuteSecs;

	}


	
	seconds = integer(time);
	
//	str_cpy(str_time_days,"");
//	str_cat_num(str_time_days," %.0f x ",	days);
//	str_cat_num(str_time_days," %.0f",		hours);


//	draw_text(str_time_days,	15,270,	vector(255,255,255));
		//draw_text(str_time_hours,	15,290,	vector(255,255,255));
		//draw_text(str_time_minutes,	15,310,	vector(255,255,255));
		//draw_text(str_time_seconds,	15,330,	vector(255,255,255));
		
	
//	str_cpy(str_time_remaining,str_time_days);
}




function timer_startup(){
		
	while(1){

		tick += time_frame;
		
		secs_world = tick / 16; 
		secs_game = secs_world % 21;
	
		timeToDate();
		
		wait(1);

	}
}




