#include "../include/land.hpp"


void Land::draw() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glutSolidCube(m_size);
    glPopMatrix();
}
