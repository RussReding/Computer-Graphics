#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define LEO 1
#define BIG_DIPPER 2
#define CANCER 3
#define ORION 4

void defaultDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clears the screen
	glBegin(GL_POINTS); //GL_LINES, GL_POLYGON
	glVertex2i(50, 50); //draws three points
	glVertex2i(130, 110);
	glVertex2i(140, 60);
	glVertex2i(270, 110);
	glVertex2i(270, 190);
	glVertex2i(290, 180);
	glVertex2i(290, 60);
	glEnd();
	glFlush();	//send all outputs
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 0.0f);

	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void createMenus() {
	int menu;

	menu = glutCreateMenu(processMenuEvents);

	glutAddMenuEntry("Leo", LEO);
	glutAddMenuEntry("Big Dipper", BIG_DIPPER);
	glutAddMenuEntry("Cancer", CANCER);
	glutAddMenuEntry("Orion", ORION);
}

void processMenuEvents(int option) {
	switch (option) {
		case LEO :
			glClear(GL_COLOR_BUFFER_BIT); //clears the screen
			glBegin(GL_POINTS); //GL_LINES, GL_POLYGON
			glVertex2i(50, 50); //draws three points
			glVertex2i(130, 110);
			glVertex2i(140, 60);
			glVertex2i(270, 110);
			glVertex2i(270, 190);
			glVertex2i(290, 180);
			glVertex2i(290, 60);
			glEnd();
			glFlush();	//send all outputs
		}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutDetachMenu(GLUT_RIGHT_BUTTON);
	glutCreateWindow("Leo Constellation");
	glutDisplayFunc(defaultDisplay);
	init();
	glutMainLoop();
	return 0;
}
