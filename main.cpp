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


void selectRoDz(const RodSelector &selection) {
	if(!env.gameOver()) {
		switch(selection.index) {
			case 0:
				env.highLight(rod_selected::left);
				break;
			case 1:
				env.highLight(rod_selected::middle);
				break;
			default:
				env.highLight(rod_selected::right);

		}
	}
}

void selectDiskFromRod(const RodSelector &selection) {\
	if(!env.gameOver()) {
		switch(selection.index) {
			case 0:
				env.select(rod_selected::left);
				break;
			case 1:
				env.select(rod_selected::middle);
				break;
			default:
				env.select(rod_selected::right);

		}
	}
}

void unselectDiskFromRod(const RodSelector & selection) {
	env.unselect();
}

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
	land.render();
	glPushMatrix();
		std::string score("Current Moves: ");
		score += std::to_string(env.move_counter);
		glDisable(GL_LIGHTING);
			glMatrixMode(GL_MODELVIEW);
			glColor3f(1.0f, 1.0f, 1.0f);
			glTranslatef(0.0f, 8.0f, 0.0f);
			glScalef(0.009f, 0.009f, 1.0f);
			glutStrokeString(GLUT_STROKE_ROMAN, (const unsigned char*)score.c_str());
		glEnable(GL_LIGHTING);
	glPopMatrix();
	if(!env.gameOver()) {
		glPushMatrix();
			std::string SCORES("YOUR SCORE IS: ");
			SCORES += std::to_string( ((float) env.move_counter )/ 255 ) + " best is 1 above is bad";
			glDisable(GL_LIGHTING);
				glMatrixMode(GL_MODELVIEW);
				glColor3f(1.0f, 1.0f, 1.0f);
				glTranslatef(-10.0f, 10.0f, 0.0f);
				glScalef(0.006f, 0.006f, 1.0f);
				glutStrokeString(GLUT_STROKE_ROMAN, (const unsigned char*)SCORES.c_str());
			glEnable(GL_LIGHTING);
		glPopMatrix();
	}
	glFlush(); 
	glutSwapBuffers();
	glutPostRedisplay();

}

void mySpecial(int key, int x, int y){
	if(!env.gameOver()) {
		if(MOVING) {

			switch(key) {
				case GLUT_KEY_RIGHT:
					env.move(direction::right);
					break;
				case GLUT_KEY_LEFT:
					env.move(direction::left);
					break;
				case GLUT_KEY_UP:
					env.move(direction::up);
					break;
				case GLUT_KEY_DOWN:
					env.move(direction::down);
					break;
			}

		}else {
			switch (key) {
				case GLUT_KEY_RIGHT:
					++CURRENT_ROD;
					selectRoDz(CURRENT_ROD);
					break;
				case GLUT_KEY_LEFT:
					--CURRENT_ROD;
					selectRoDz(CURRENT_ROD);
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
}

void myKeyboard(unsigned char key, int x, int y) {
	if(!env.gameOver() ) {
		switch (key) {
			case 27: // escape
				glutLeaveMainLoop();
				break;
			case 13: // return
				if(!MOVING) {
					MOVING = true;
					// call functions on game
					selectDiskFromRod(CURRENT_ROD);
				}else {
					MOVING = false;
					//call functions on game
					unselectDiskFromRod(CURRENT_ROD);
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