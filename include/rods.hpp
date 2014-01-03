#pragma once
#include "gl.hpp"
#include "point.hpp"
#include "color.hpp"

class Rod{
private:
    Point origin;
    GLUquadricObj *quad;
    float rgba[4];
    bool highlighted;
    float dir;
public:
    Rod(Point origin, Color rgba);
    void draw();
    void highlight();
    void unhighlight();
};