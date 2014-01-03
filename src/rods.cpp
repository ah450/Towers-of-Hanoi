#include "../include/rods.hpp"

constexpr double radius = 0.25;
constexpr double height = 10;
constexpr int slices = 200;
constexpr int stacks = 10;

Rod::Rod(Point origin) : origin(origin), quad(gluNewQuadric()) {
    gluQuadricDrawStyle(quad, GLU_FILL);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricOrientation(quad, GLU_OUTSIDE);

}

void Rod::draw() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef( 90,1.0f, 0.0f,0.0);
    gluCylinder(quad, radius, radius,  height, slices, stacks);
    glPopMatrix();
}


