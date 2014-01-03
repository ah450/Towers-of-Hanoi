#pragma once
#include "gl.hpp"
#include "point.hpp"

class Disk{
private:
    Point disk_origin;
	double in_radius;
	double out_radius;
    double nsides;
    double rings;
public:
	Disk(Point ,double, double);
    Disk(Point, double, double, double, double);
	void drawDisk();
	void moveDisk();//fix me
};