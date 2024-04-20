#include <string>
#include <fstream>
#include <cmath>

#include "celf.h"

Canvas::Canvas(){
	height = width = DEFAULT_SIZE;
	pixels = new int[height*width];
}

Canvas::Canvas(int w, int h){
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

errorno Canvas::drawLine(int x1, int y1, int x2, int y2, int thickness, int color){
	int x_min, x_max, y_min, y_max;
	{
		if (x1 < x2){
			x_min = x1;	
			x_max = x2;
			y_min = y1;	
			y_max = y2;
		}else{
			x_min = x2;	
			x_max = x1;
			y_min = y2;	
			y_max = y1;
		}
	}

	if ((x_max - x_min) == 0){
		for (int iy = y_min; iy <= y_max; iy++){
			pixels[iy*width + x_min] = color;
		}
	}

	float m0 = (y_max - y_min)/(float)(x_max - x_min);

	for (int iy = y_min; iy <= y_max; iy++){
		for (int ix = x_min; ix <= x_max; ix++){
			if ((ix - x_min) == 0) continue;
			float m = (iy - y_min)/(float)(ix - x_min);
			if (m == m0){
				pixels[iy*width + ix] = color;
				for (int t = 1; t < thickness; t++){
					if( iy - t/2 > y_min && iy + t/2 < y_max &&  ix - t/2 > x_min && ix + t/2 < x_max ){
						pixels[(iy - t)*width + ix] = color;
						pixels[(iy + t)*width + ix] = color;
						pixels[iy*width + ix + t] = color;
						pixels[iy*width + ix - t] = color;
					}
				}
			}
		}
	}
	return OK;
}

errorno Canvas::drawRect( int wid, int len, int x, int y, int color){
	
	for (int iy = y; iy < len + y; iy++){
		if (iy > 0 && iy < height){
			for (int ix = x; ix < wid + x; ix++){
				if (ix > 0 && ix < width){
					pixels[iy*width + ix] = color;
				}
			}
		}
	}

	return OK;
}

errorno Canvas::drawEmptyCircle(int radius,int thickness, int x, int y, int color){
	
	for (int iy = y - radius - thickness; iy <= y + radius + thickness; iy++){
		if (iy > 0 && iy < height){
			for (int ix = x - radius - thickness; ix <= x + radius + thickness; ix++){
				if (ix > 0 && ix < width){
					int distance = sqrt((x - ix)*(x - ix) + (y - iy)*(y - iy));		
					if (abs(distance - radius) <= thickness/2){
						pixels[iy*width + ix] = color;
					}
				}
			}
		}
	}

	return OK;
}

errorno Canvas::drawCircle(int radius,int x, int y, int color){
	
	for (int iy = y - radius; iy <= y + radius; iy++){
		if (iy > 0 && iy < height){
			for (int ix = x - radius; ix <= x + radius; ix++){
				if (ix > 0 && ix < width){
					int distance = sqrt((x - ix)*(x - ix) + (y - iy)*(y - iy));		
					if (distance < radius){
						pixels[iy*width + ix] = color;
					}
				}
			}
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

