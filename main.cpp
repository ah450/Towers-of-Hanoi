
#include <GL/freeglut.h>
#include <GL/glu.h>

void SetupLights() 
{ 
	GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f}; 	 
	GLfloat mat_diffuse[]={0.1f,0.6f,0.1,1.0f}; 
	GLfloat mat_specular[]={1.0f,1.0f,1.0,1.0f}; 
	GLfloat light_position[]={1.0f, 1.0f, 1.0f, 0.0f}; 
	glLightfv(GL_LIGHT0,GL_POSITION,light_position); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse); 
	glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient); 
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular); 
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0); 
}


void myDisplay(){

	//SetupLights();
	
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	gluPerspective(45.0f, 100/64, 0.1f, 1000.0f);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	 
	gluLookAt(10,10, 10, 0, 0, 0,0.0,1.0,0.0); 
	 
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); 

	glColor3f(0.5f,0.5f,0.5f);
	GLUquadric*  quadric = gluNewQuadric();
	//gluQuadricDrawStyle(quadric, render1);
    //gluDisk(quadric, 1, 1, 3, 20);
	// glutSolidCube(5);

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

	glClearColor(1.0,1.0,1.0,1.0);
	
	glutMainLoop(); // go into a perpetual loop 
}