#include "../include/rods.hpp"
#include <cstring>
constexpr double radius = 0.15;
constexpr double height = 10;
constexpr int slices = 200;
constexpr int stacks = 10;

Rod::Rod(Point origin, Color rgba) : origin(origin), quad(gluNewQuadric()) {

    gluQuadricDrawStyle(quad, GLU_FILL);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricOrientation(quad, GLU_OUTSIDE);
    gluQuadricTexture(quad, GLU_TRUE);
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



}


