#pragma once
#include "gl.hpp"
#include "point.hpp"
#include "color.hpp"

class Rod{
private:
    Point origin;
    GLUquadricObj *quad;
    float rgba[4];
  //  GLuint texture;
public:
    Rod(Point origin, Color rgba);
    void draw();
};