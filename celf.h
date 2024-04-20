#pragma once 

#include <string>
#include <fstream>

#define DEFAULT_SIZE 800

enum errorno {
	FATAL = -1,
	OK = 0
};

class Canvas {
public:
	int height;
	int  width;
	int* pixels;
public:
	Canvas();
	Canvas(int h, int w);
	errorno fill(int color);
	errorno drawRect(int length,int width, int x, int y, int color);
	errorno saveToPPM(std::string name);
	~Canvas();
};
