#include "../include/land.hpp"


void Land::draw() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0,-10,0);
    glutSolidCube(m_size);
    glPopMatrix();
}
