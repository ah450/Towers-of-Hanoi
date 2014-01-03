#pragma once
#include "gl.hpp"
#include "point.hpp"
#include "string"

class Land{
private:
    double m_size;
public:
    Land(double size) :m_size(size){}
    void render();
    void init();
    GLuint loadTexture(const std::string filename, int &width, int &height);
};