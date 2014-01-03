#include "../include/land.hpp"
#include "../include/color.hpp"

void Land::draw() {
	float rgba[] ={0,0,1,0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, rgba);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0,-10,0);
    glScaled(3,0.25,2);
    glutSolidCube(m_size);
    glPopMatrix();

    float rgba2[] ={1,0,0,0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, rgba2);
    glPushMatrix();
    glTranslated(0,-8,0);
    glScaled(3,0.25,2);
    glutSolidCube(m_size-1);
    glPopMatrix();

	float rgba3[] ={1,1,0,0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, rgba3);
    glPushMatrix();
    glTranslated(0,-6,0);
    glScaled(3,0.25,2);
    glutSolidCube(m_size-2);
    glPopMatrix();    
}
