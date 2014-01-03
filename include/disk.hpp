#pragma once
#include "gl.hpp"
#include "point.hpp"
#include "color.hpp"

class Disk{
private:
    Point disk_origin;
    float rgba[4]; 
	double in_radius;
	double out_radius;
    double nsides;
    double rings;
public:
	Disk(Point, Color ,double, double);
    Disk(Point, Color ,double, double, double, double);
	void draw();
	void move();//fix me
};