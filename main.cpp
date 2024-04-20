#include <iostream>

#include "celf.h"

int main (void){
	Canvas canvas;
	canvas.fill(0xFF1817AE);
	canvas.drawRect(400,400,400,400,0xFFAFAFAF);
	canvas.drawRect(200,200,600,600,0xFFFFAAAA);
	canvas.saveToPPM("sample.ppm");
}
