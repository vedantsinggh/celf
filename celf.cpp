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

errorno Canvas::saveToPPM(std::string name){

	std::fstream file;
	file.open(name, std::ios::out);	

	if (!file) return FATAL;	

	file << "P3 " << width << " " << height << " " << 255 << "\n";

	for (int x = 0; x < width; ++x){
		for (int y = 0; y < height; ++y){
			int bytes[3] = {
				(*pixels>>(8*2))&0xFF,
				(*pixels>>(8*1))&0xFF,
				(*pixels>>(8*0))&0xFF,
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
