#include <iostream>

#include "celf.h"

int main (void){

	int height = 700;
	int width  = 400;
	Canvas canvas( width, height);

	canvas.fill(0xFF1817AE);
	canvas.drawRect( width/2, height/2, width/2, height/2, 0xFFAFAFAF);
	canvas.drawCircle( width/4, width/2, height/2, 0xFF00FAFA);
	canvas.saveToPPM("sample.ppm");

}
