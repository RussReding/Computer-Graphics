#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#define WIDTH 500
#define HEIGHT 500

int prevX;
int prevY;

char keyOption = 'd';

void keyboard(unsigned char keystroke, int x, int y);
void mouse(int button, int state, int x, int y);
void drawLine(int x, int y);
void drawDot(int x, int y);
void defaultDisplay(void);
void setWindow(float left, float right, int bottom, int top);
void init(void);

static int win;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);
	win = glutCreateWindow("Draw Dots and Lines");
	init();
	glutDisplayFunc(defaultDisplay);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	
	// enter the main loop
	glutMainLoop();
	return 0;
}

void defaultDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	setWindow(0, WIDTH, 0, HEIGHT);
}

void setWindow(float left, float right, int bottom, int top) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);

	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void keyboard(unsigned char keystroke, int x, int y) {
	switch (keystroke) {
	case 'd':
		keyOption = 'd';
		break;

	case 'l':
		keyOption = 'l';
		break;
	}
}

void mouse(int button, int state, int x, int y) {
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
		if (keyOption == 'd') {
			drawDot(x, y);
		}
		if (keyOption == 'l') {
			drawLine(x, y);
		}
	}
}

void drawDot(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, HEIGHT - y);
	glEnd();
	glFlush();
	prevX = x;
	prevY = y;
}

void drawLine(int x, int y) {
	if (prevX != NULL && prevY != NULL) {
		glBegin(GL_LINES);
		glVertex2i(prevX, HEIGHT - prevY);
		glVertex2i(x, HEIGHT - y);
		glEnd();
		glBegin(GL_POINTS);
		glVertex2i(x, HEIGHT - y);
		glEnd();
		glFlush();
	}
	prevX = x;
	prevY = y;
}