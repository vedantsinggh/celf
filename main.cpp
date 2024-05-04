#include <iostream>

#include "celf.h"

int main (void){

	int height = 400;
	int width  = 400;
	int lineThickness = 10;
	Canvas canvas( width, height);

	canvas.fill(0xFF181818);
	canvas.drawLine( width/4, height/4, 3*width/4,3*height/4, lineThickness, 0xFFFFFFFF);
	canvas.drawLine( width/4, 3*height/4, 3*width/4,height/4, lineThickness, 0xFFFFFFFF);
	canvas.drawLine( width/2, height/2, width/2,height/4, lineThickness, 0xFFFFFFFF);
	canvas.drawEmptyCircle(200, lineThickness, 0,0, 0xFFFFFFFF);
	canvas.saveToPPM("sample.ppm");

}
