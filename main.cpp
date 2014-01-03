#include "./include/gl.hpp"
#include "./include/rods.hpp"
#include "./include/land.hpp"

Rod testRod({0.0, 5.0, 0.0});
Land land({3});
const float light_position[4] = {0.0f, 1.0f, 0.5f, 0.0f}; 


void myDisplay(){

	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); 

	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	gluPerspective(45.0f, 1000/680, 0.1f, 1000.0f);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	 
	gluLookAt(0,0, 30, 0, 0, 0, 0,1.0,0); 
	// define light pos
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//
	

	glColor3f(0.5f,0.5f,0.5f);
	GLUquadric*  quadric = gluNewQuadric();
	//gluQuadricDrawStyle(quadric, render1);
    //gluDisk(quadric, 1, 1, 3, 20);
	// glutSolidCube(5);
	land.draw();
	testRod.draw();
	glFlush(); 
	glutSwapBuffers();
	glutPostRedisplay();

}
int main(int argc, char** argv) 
{ 	
	
	glutInit(&argc, argv); // initialize the toolkit 
	 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH); // set 
	 
	glutInitWindowSize(1000,680); // set window size 
	glutInitWindowPosition(200, 150); // set window position on 
	 
	glutCreateWindow("3D LUNAR LANDER"); // open the screen window 
	glutDisplayFunc(myDisplay); // register redraw function 

	glShadeModel(GL_SMOOTH); 
	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_NORMALIZE); 
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(0.0,0.0,0.0,1.0);
	
	glutMainLoop(); // go into a perpetual loop 
}