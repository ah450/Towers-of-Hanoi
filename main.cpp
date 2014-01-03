#include "./include/gl.hpp"
#include "include/environment.hpp"
#include "./include/rods.hpp"
#include "./include/land.hpp"
#include "include/disk.hpp"
#include "./include/texture.hpp"

unsigned int width = 1000;
unsigned int height = 680;
double eyeX = 0;
double eyeY = 20;
double eyeZ = 30;
static bool MOVING = false;

Environment env;




const float light_position[4] = {0.0f, 0.75f, 0.5f, 0.0f}; 


void myDisplay(){

	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 	
	gluPerspective(45.0f, width/height, 0.1f, 1000.0f);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 	 
	gluLookAt(eyeX,eyeY, eyeZ, 0, 0, 0, 0,1.0,0); 
	// define light pos
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	env.draw();
	glFlush(); 
	glutSwapBuffers();
	glutPostRedisplay();

}

void mySpecial(int key, int x, int y){
	if(MOVING) {

	}else {
		switch (key) {
			case GLUT_KEY_RIGHT:
				break;
			case GLUT_KEY_LEFT:
				break;
		}
	}	
}

void myKeyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 27: // escape
			glutLeaveMainLoop();
			break;
	}
}

int main(int argc, char** argv) 
{ 	
	
	glutInit(&argc, argv); // initialize the toolkit 
	 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH); // set 
	 
	glutInitWindowSize(width, height); // set window size 
	const int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	const int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition((screenWidth - width) / 2, (screenHeight - height) /2); // set window position on 
	 
	glutCreateWindow("Towers of Hanoi"); // open the screen window 
	glutDisplayFunc(myDisplay); // register redraw function 

	glutSpecialFunc(mySpecial);
	glutKeyboardFunc(myKeyboard);
	glShadeModel(GL_SMOOTH); 
	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	const float whiteLight[4] = {0.8f, 0.8f, 0.8f, 1.0f};
	const float spotCutoff = 60.0f;
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteLight);
	glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, &spotCutoff);
	glClearColor(0.0,0.0,0.0,1.0);
	
	glutMainLoop(); // go into a perpetual loop 
}