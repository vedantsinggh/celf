#include <iostream>

#include "celf.h"

int main (void){

	int height = 400;
	int width  = 400;
	Canvas canvas( width, height);

	canvas.fill(0xFF1817AE);
	canvas.drawRect( width/2, height/2, width/2, height/2, 0xFFAFAFAF);
	canvas.drawCircle( height/4, 100, width/2, height/2, 0xFF00FAFA);
	canvas.drawSolidCircle( height/4, width/4, height/4, 0xFFEE15AA);
	canvas.saveToPPM("sample.ppm");

}
