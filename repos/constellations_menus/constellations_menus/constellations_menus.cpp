#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#define LEO 0
#define BIG_DIPPER 1
#define CANCER 2
#define ORION 3

#define WIDTH 500
#define HEIGHT 500

GLfloat angle = 0.0;	/*Rotationsvinkel*/

void createMenu(void);
void menuOptions(int value);
void keyboard(unsigned char keystroke, int x, int y);
void mouse(int button, int state, int x, int y);
void defaultDisplay(void);
void init(void);

static int win;
static int menuID;
static double size;
static int curr_opt = LEO;

int main(int argc, char** argv) {

	// normal initialisation
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);

	win = glutCreateWindow("Constellations with Menus");

	// put all the menu functions in one nice procedure
	createMenu();

	// set the clearcolor and the callback
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(defaultDisplay);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	init();
	// enter the main loop
	glutMainLoop();
	return 0;
}
void createMenu(void) {

	menuID = glutCreateMenu(menuOptions);

	glutAddMenuEntry("Leo", LEO);
	glutAddMenuEntry("Big Dipper", BIG_DIPPER);
	glutAddMenuEntry("Cancer", CANCER);
	glutAddMenuEntry("Orion", ORION);
	// Let the menu respond on the right mouse button
	glutAttachMenu(GLUT_RIGHT_BUTTON);


}

void defaultDisplay(void) {
	menuOptions(LEO);
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 0.0f);

	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void menuOptions(int option) {
	glClear(GL_COLOR_BUFFER_BIT); //clears the screen
	glBegin(GL_POINTS); //GL_LINES, GL_POLYGON
	switch (option) {
		case LEO :
			curr_opt = LEO;
			glVertex2i(50 * 2, 50 * 1.75);
			glVertex2i(130 * 2, 110 * 1.75);
			glVertex2i(140 * 2, 60 * 1.75);
			glVertex2i(270 * 2, 110 * 1.75);
			glVertex2i(270 * 2, 190 * 1.75);
			glVertex2i(290 * 2, 180 * 1.75);
			glVertex2i(290 * 2, 60 * 1.75);
			glVertex2i(220 * 2, 140 * 1.75);
			glVertex2i(230 * 2, 160 * 1.75);
			break;
		
		case BIG_DIPPER :
			curr_opt = BIG_DIPPER;
			glVertex2i(289 * 1.75, 190 * 1.75);
			glVertex2i(320 * 1.75, 128 * 1.75);
			glVertex2i(239 * 1.75, 67 * 1.75);
			glVertex2i(194 * 1.75, 101 * 1.75);
			glVertex2i(129 * 1.75, 83 * 1.75);
			glVertex2i(75 * 1.75, 73 * 1.75);
			glVertex2i(74 * 1.75, 74 * 1.75);
			glVertex2i(20 * 1.75, 10 * 1.75);
			break;
		
		case CANCER :
			curr_opt = CANCER;
			glVertex2i(250, 300);
			glVertex2i(310, 210);
			glVertex2i(350, 150);
			glVertex2i(310, 30);
			glVertex2i(400, 120);
			glVertex2i(520, 60);
			break;
		
		case ORION :
			curr_opt = ORION;
			glVertex2i(30 * 2, 200 * 1.75);
			glVertex2i(60 * 2, 100 * 1.75);
			glVertex2i(60 * 2, 20 * 1.75);
			glVertex2i(90 * 2, 110 * 1.75);
			glVertex2i(110 * 2, 120 * 1.75);
			glVertex2i(140 * 2, 190 * 1.75);
			glVertex2i(160 * 2, 40 * 1.75);
			glVertex2i(120 * 2, 230 * 1.75);
			glVertex2i(200 * 2, 200 * 1.75);
			glVertex2i(200 * 2, 210 * 1.75);
			glVertex2i(190 * 2, 230 * 1.75);
			glVertex2i(200 * 2, 190 * 1.75);
			glVertex2i(180 * 2, 160 * 1.75);
			glVertex2i(10 * 2, 230 * 1.75);
			break;
		default :
			printf("ERROR: Unknown Constellation Input");
	}
	glEnd();
	glFlush();	//send all outputs
}

void keyboard(unsigned char keystroke, int x, int y) {
	switch (keystroke) {
	case 'r' :
		glColor3f(1.0f, 0.0f, 0.0f);
		break;

	case 'g':
		glColor3f(0.0f, 1.0f, 0.0f);
		break;

	case 'b':
		glColor3f(0.0f, 0.0f, 1.0f);
		break;

	case 'w':
		glColor3f(1.0f, 1.0f, 1.0f);
		break;
	}
	menuOptions(curr_opt);
}

void mouse(int button, int state, int x, int y) {
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
		if (y < (HEIGHT / 2)) {
			size++;
		}
		else {
			size--;
		}
		glPointSize(size);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0, 640.0, 0.0, 480.0);
		

		menuOptions(curr_opt);
		if (size > 20.0) {
			size = 1.0;
		}
		if (size < 0) {
			size = 20.0;
		}
	}
	
}