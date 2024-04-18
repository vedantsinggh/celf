#include <iostream>

#include "celf.h"

int main (void){
	Canvas canvas;
	canvas.fill(0xFFFF0000);
	canvas.saveToPPM("sample.ppm");
}
