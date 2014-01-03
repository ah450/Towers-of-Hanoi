#pragma once
#include "gl.hpp"
#include "point.hpp"
class Land{
private:
    double m_size;
    GLUquadricObj *quad;
public:
    Land(double size) :m_size(size){}
    void draw();
};