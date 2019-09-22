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

static int win;
void defaultDisplay(void);
void init(void);
void setWindow(float left, float right, int bottom, int top);
void delay(int time);
void animateBezier(void);
void calcBezier(void);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);
	win = glutCreateWindow("Bezier Curve");
	init();
	glutDisplayFunc(defaultDisplay);
	animateBezier();
	// enter the main loop
	glutMainLoop();
	return 0;
}

void defaultDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	setWindow(0, WIDTH, 0, HEIGHT);
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 0.0f);

	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void setWindow(float left, float right, int bottom, int top) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void delay(int time) {
	Sleep(10000);
	printf("I'm awake!");
}

void animateBezier() {

}

void calcBezier() {

}
