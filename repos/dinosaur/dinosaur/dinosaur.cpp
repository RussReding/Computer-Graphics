#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <fstream>
using namespace std;

void display();

void drawPolyLineFile(const char* fileName) {
	fstream inStream;
	inStream.open(fileName, ios::in); //open the file

	if (inStream.fail()) return;

	glClear(GL_COLOR_BUFFER_BIT); //clears the screen
	GLint numpolys, numLines, x, y;
	inStream >> numpolys; //read the number of polylines

	for (int j = 0; j < numpolys; j++) { //read each polyline
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < numLines; i++) {
			inStream >> x >> y; //read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

void setWindow(float left, float right, int bottom, int top) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);

	setWindow(0, 1024.0, 0, 768.0);
	drawPolyLineFile("C:\\Users\\Russell Reding\\source\\repos\\dinosaur\\dino.dat"); //Edit this path for your directory

	glFlush();
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 1.0f, 1.0f);

	glPointSize(14.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Dinosaur");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return(0);

}