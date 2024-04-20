#include <iostream>
#include <string>
#include <fstream>

#include "celf.h"

Canvas::Canvas(){
	height = width = DEFAULT_SIZE;
	pixels = new int[height*width];
}

Canvas::Canvas(int h, int w){
	height = h;
	width  = w;
	pixels = new int[height*width];
}

errorno Canvas::fill(int color){
	for (int i = 0; i < height*width; i++){
		(pixels[i]) = color;
	}
	return OK;
}

errorno Canvas::drawRect(int l, int w, int x, int y, int color){
	
	for (int iy = y; iy < l + y; iy++){
		for (int ix = x; ix < w + x; ix++){
			pixels[iy*width + ix] = color;
		}
	}
	return OK;

}

errorno Canvas::saveToPPM(std::string name){

	std::fstream file;
	file.open(name, std::ios::out);	

	if (!file) return FATAL;	

	file << "P3 " << width << " " << height << " " << 255 << "\n";

	for (int y = 0; y < height; ++y){
		for (int x = 0; x < width; ++x){
			int bytes[3] = {
				(pixels[y*width + x]>>(8*2))&0xFF,
				(pixels[y*width + x]>>(8*1))&0xFF,
				(pixels[y*width + x]>>(8*0))&0xFF,
			};
			file << bytes[0] << " " << bytes[1] << " " << bytes[2] << " ";
		}
		file << "\n";
	}

	file.close();
	return OK; 
}

Canvas::~Canvas(){
	delete[] pixels;
}
