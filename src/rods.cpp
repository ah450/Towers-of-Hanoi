#include "../include/rods.hpp"
#include <cstring>
constexpr double radius = 0.15;
constexpr double height = 10;
constexpr int slices = 200;
constexpr int stacks = 10;

Rod::Rod(Point origin, Color rgba) : origin(origin), quad(gluNewQuadric()), highlighted(false), dir(1) {

    gluQuadricDrawStyle(quad, GLU_FILL);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricOrientation(quad, GLU_OUTSIDE);
    std::memcpy(this->rgba, reinterpret_cast<const void *>(&rgba), 4 * sizeof(float));
   
}

void Rod::draw() {

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(origin.x, origin.y - (height / 2) , origin.z);
    glRotatef( -90,1.0f, 0.0f,0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, rgba);
    gluCylinder(quad, radius, radius,  height, slices, stacks);
    glPopMatrix();
    if(highlighted) {
        rgba[3] += 0.025f * dir;
        if(rgba[3] > 1.0f) {
            dir = -1;
        }
        if(rgba[3] <= 0.25f) {
            dir = 1;
        }     
    }

}

void Rod::highlight() {
    highlighted = true;
    rgba[3] = 0.0f;
}

void Rod::unhighlight() {
    highlighted = false;
    rgba[3] = 1.0f;
    dir = 1;
}


