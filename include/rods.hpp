#pragma once
#include "gl.hpp"
#include "point.hpp"
class Rod{
private:
    Point origin;
    GLUquadricObj *quad;
public:
    Rod(Point origin);
    void draw();
};