#pragma once
#include "gl.hpp"
#include "point.hpp"
#include "color.hpp"
#include "vector.hpp"

class Disk{
private:
    Point disk_origin;
    float rgba[4];
    GLUquadricObj *quad;
	double in_radius;
	double out_radius;
    int slices;
    int loops;
    void construct_disk();
public:
	Disk(Point, Color ,double, double);
    Disk(Point, Color ,double, double, int, int);
    bool operator>(Disk & d){return this->out_radius > d.out_radius;}
    bool operator==(const Disk & other) {
        return (out_radius == other.out_radius);
    }
    bool operator!=(const Disk &other) {
        return ! (this->operator==(other));
    }
	void draw();
	void move(const vector&);
    Point get_origin();
    void set_origin(Point);
};