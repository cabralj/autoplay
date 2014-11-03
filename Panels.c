
BMAP* fail_bmap 		= "sprites\\error.tga";
BMAP* curtain_bmap 	= "images\\curtain.bmp";


PANEL* fail =
{
	pos_x = 0; pos_y = 0;
  	window (260,	110,	200,	200,	fail_bmap,	0,	0);
  	layer = 10;
}


PANEL* curtain =
{
	pos_x = 0; pos_y = 0;
  	window (0,	0,	720,	480,	curtain_bmap,	0,	0);
  	layer = 20;
}
