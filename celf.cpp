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

//TODO: rewrite this function
errorno Canvas::drawLine(int x1, int y1, int x2, int y2, int thickness, int color){
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;

    int err = dx - dy;

    int x = x1, y = y1;

    int halfThickness = thickness / 3;

    while (true) {
        for (int i = -halfThickness; i <= halfThickness; i++) {
            for (int j = -halfThickness; j <= halfThickness; j++) {
                if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                    pixels[(y + j) * width + (x + i)] = color;
                }
            }
        }

        if (x == x2 && y == y2) break;

        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (err2 < dx) {
            err += dx;
            y += sy;
        }
    }

    return OK;
}

errorno Canvas::drawRect( int wid, int len, int x, int y, int color){
	
	for (int iy = y; iy < len + y; iy++){
		if (iy >= 0 && iy <= height){
			for (int ix = x; ix < wid + x; ix++){
				if (ix >= 0 && ix <= width){
					pixels[iy*width + ix] = color;
				}
			}
		}
	}

	return OK;
}

errorno Canvas::drawEmptyCircle(int radius,int thickness, int x, int y, int color){
	
	for (int iy = y - radius - thickness; iy <= y + radius + thickness; iy++){
		if (iy >= 0 && iy <= height){
			for (int ix = x - radius - thickness; ix <= x + radius + thickness; ix++){
				if (ix >= 0 && ix <= width){
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
		if (iy >= 0 && iy <= height){
			for (int ix = x - radius; ix <= x + radius; ix++){
				if (ix >= 0 && ix <= width){
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

