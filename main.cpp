#include "./include/gl.hpp"
#include "include/environment.hpp"
#include "./include/rods.hpp"
#include "./include/land.hpp"
#include "include/disk.hpp"
#include <SFML/Audio/Music.hpp>
#include <cmath>


unsigned int width = 1000;
unsigned int height = 680;
double eyeX = 1;
double eyeY = 20;
double eyeZ = 30;
static bool MOVING = false;

Land land({8});
static sf::Music music;
static bool playing;
static float currentVolume;

static float deltaAngleX = 0;
static float deltaAngleY = 0;


struct RodSelector {
	unsigned int index;
	RodSelector() : index(0){}
	RodSelector & operator--(){
		index--;
		if(index < 0 ) {
			index = 2;
		}
		return *this;
	}
	RodSelector & operator++() {
		index++;
		if(index > 2) {
			index = 0;
		}
		return *this;
	}
};
static RodSelector CURRENT_ROD;

Environment env;




const float light_position_1[4] = {0.0f, 0.75f, 0.5f, 0.0f}; 
const float light_position_2[4] = {0.0f, 0.75f, -0.5f, 0.0f}; 


void myDisplay(){

	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); 

	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	gluPerspective(45.0f, width/height, 0.1f, 1000.0f);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 	 
	gluLookAt(eyeX * std::sin(deltaAngleY) ,eyeY, eyeZ * std::cos(deltaAngleX) , 0, 0, 0, 0,1.0,0); 
	// define light pos
	glLightfv(GL_LIGHT0, GL_POSITION, light_position_1);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position_2);
	env.draw();

	
	land.draw();
	
	land.render();
	glFlush(); 
	glutSwapBuffers();
	glutPostRedisplay();

}

void mySpecial(int key, int x, int y){
	if(MOVING) {

	}else {
		switch (key) {
			case GLUT_KEY_RIGHT:
				++CURRENT_ROD;
				break;
			case GLUT_KEY_LEFT:
				--CURRENT_ROD;
				break;
		}
	}

	switch(key) {
		case GLUT_KEY_PAGE_DOWN:
			currentVolume -= 5.0f;
			if(currentVolume < 0) {
				currentVolume = 0;
			}
			music.setVolume(currentVolume);
			break;
		case GLUT_KEY_PAGE_UP:
			currentVolume += 5.0f;
			if(currentVolume > 100.0f) {
				currentVolume = 100.0f;
			}
			music.setVolume(currentVolume);
			break;
	}	
}

void myKeyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 27: // escape
			glutLeaveMainLoop();
			break;
		case 13: // return
			if(!MOVING) {
				MOVING = true;
				// call functions on game
			}else {
				MOVING = false;
				//call functions on game
			}
			break;
		case 32:
			if(playing) {
				music.pause();
				playing = false;
			}else {
				music.play();
				playing = true;
			}
	}
}


void myMouseMotion(int x, int y) {

	// this will only be true when the left button is down

		// update deltaAngle
		deltaAngleX = x * 0.005f;
		deltaAngleY = y * 0.005f;
		// update camera's direction
		
}

int main(int argc, char** argv) 
{ 	
	music.openFromFile("Antti_Martikainen_-_At_the_Gates_of_Babylon.ogg");
	music.setLoop(true);
	music.play();
	playing = true;
	currentVolume = 100.0f;
	glutInit(&argc, argv); // initialize the toolkit 
	 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH); // set 
	 
	glutInitWindowSize(width, height); // set window size 
	const int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	const int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition((screenWidth - width) / 2, (screenHeight - height) /2); // set window position on 
	 
	glutCreateWindow("Towers of Hanoi"); // open the screen window 
	glutDisplayFunc(myDisplay); // register redraw function 
	glutPassiveMotionFunc(myMouseMotion);
	glutSpecialFunc(mySpecial);
	glutKeyboardFunc(myKeyboard);
	glShadeModel(GL_SMOOTH); 
	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	const float whiteLight[4] = {0.8f, 0.8f, 0.8f, 1.0f};
	const float spotCutoff = 60.0f;
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteLight);
	glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, &spotCutoff);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, whiteLight);
	glClearColor(0.0,0.0,0.0,1.0);
	land.init();
	glutMainLoop(); // go into a perpetual loop 
}