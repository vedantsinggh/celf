#pragma once 

#include <string>

#define DEFAULT_SIZE 400

enum errorno {
	FATAL = -1,
	OK = 0
};

class Canvas {

public:
	int height;
	int  width;
public:
	Canvas();
	Canvas(int width, int height);
	errorno fill(int color);
	errorno drawRect(int wid,int len, int x, int y, int color);
	errorno drawSolidRect(int wid,int len, int x, int y, int color);
	errorno drawCircle(int radius,int thickness, int x, int y, int color);
	errorno drawSolidCircle(int radius, int x, int y, int color);
	errorno saveToPPM(std::string name);
	~Canvas();

private:
	int* pixels;
};


// TODO: drawLine
// TODO: drawRect
// TODO: drawTriangle
// TODO: drawArc
// TODO: drawSolidArc

