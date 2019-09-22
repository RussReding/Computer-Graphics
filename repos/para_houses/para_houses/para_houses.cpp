#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 750

#define ROWS 5
#define COLUMNS 5

int dinoX = WINDOW_WIDTH / 2;
int dinoY = WINDOW_HEIGHT / 2;

class GLintPoint {
public:
	GLint x, y;
};

struct house_props {
	GLint scale_width;
	GLint scale_height;
	GLint chimney_r;
	GLint chimney_g;
	GLint chimney_b;
	GLint house_r;
	GLint house_g;
	GLint house_b;
	GLint door_r;
	GLint door_g;
	GLint door_b;
	GLint window_r;
	GLint window_g;
	GLint window_b;
	GLint destroyed;
};

house_props houses[ROWS][COLUMNS] = { {0} };

void display();

void generateHouses(GLint width, GLint height) {
	for (int rows = 0; rows < ROWS; rows++) {
		for (int columns = 0; columns < COLUMNS; columns++) {
			houses[rows][columns].scale_width = (rand() % (width - 100)+1);
			houses[rows][columns].scale_width = width - houses[rows][columns].scale_width;
			houses[rows][columns].scale_height = (rand() % (height- 100 ) + 1);
			houses[rows][columns].scale_height = height - houses[rows][columns].scale_height;

			houses[rows][columns].chimney_r = rand() % 255;
			houses[rows][columns].chimney_g = rand() % 255;
			houses[rows][columns].chimney_b = rand() % 255;

			houses[rows][columns].house_r = rand() % 255;
			houses[rows][columns].house_g = rand() % 255;
			houses[rows][columns].house_b = rand() % 255;

			houses[rows][columns].door_r = rand() % 255;
			houses[rows][columns].door_g = rand() % 255;
			houses[rows][columns].door_b = rand() % 255;

			houses[rows][columns].window_r = rand() % 255;
			houses[rows][columns].window_g = rand() % 255;
			houses[rows][columns].window_b = rand() % 255;
		}
	}
}

void parameterizedHouse(house_props house) {
	GLintPoint peak;
	peak.x = house.scale_width / 2;
	peak.y = house.scale_width / 2;
	//Chimney
	glBegin(GL_POLYGON);
	glColor3ub(house.chimney_r, house.chimney_g, house.chimney_b);
	glVertex2i(peak.x - house.scale_width / 3, peak.y);
	glVertex2i(peak.x - house.scale_width / 5, peak.y);
	glVertex2i(peak.x - house.scale_width / 5, peak.y - house.scale_height / 2);
	glVertex2i(peak.x - house.scale_width / 3, peak.y - house.scale_height / 2);
	glEnd();
	//House Outline
	glBegin(GL_POLYGON);
	glColor3ub(house.house_r, house.house_g, house.house_b);
	glVertex2i(peak.x, peak.y);
	glVertex2i(peak.x + house.scale_width / 2, 10 + peak.y - 3 * house.scale_height / 7);
	glVertex2i(peak.x + house.scale_width / 3, 10 + peak.y - 3 * house.scale_height / 7);
	glVertex2i(peak.x + house.scale_width / 3, 10 + peak.y - house.scale_height);
	glVertex2i(peak.x - house.scale_width / 3, 10 + peak.y - house.scale_height);
	glVertex2i(peak.x - house.scale_width / 3, 10 + peak.y - 3 * house.scale_height / 7);
	glVertex2i(peak.x - house.scale_width / 2, 10 + peak.y - 3 * house.scale_height / 7);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2i(peak.x, peak.y);
	glVertex2i(peak.x + house.scale_width / 2, 10 + peak.y - 3 * house.scale_height / 7);
	glVertex2i(peak.x + house.scale_width / 3, 10 + peak.y - 3 * house.scale_height / 7);
	glVertex2i(peak.x + house.scale_width / 3, 10 + peak.y - house.scale_height);
	glVertex2i(peak.x - house.scale_width / 3, 10 + peak.y - house.scale_height);
	glVertex2i(peak.x - house.scale_width / 3, 10 + peak.y - 3 * house.scale_height / 7);
	glVertex2i(peak.x - house.scale_width / 2, 10 + peak.y - 3 * house.scale_height / 7);
	glEnd();
	//Door
	glBegin(GL_POLYGON);
	glColor3ub(house.door_r, house.door_g, house.door_b);
	glVertex2i(peak.x + house.scale_width / 8, 10 + peak.y - house.scale_height);
	glVertex2i(peak.x + house.scale_width / 8, 10 + peak.y - house.scale_height / 1.5);
	glVertex2i(peak.x - house.scale_width / 8, 10 + peak.y - house.scale_height / 1.5);
	glVertex2i(peak.x - house.scale_width / 8, 10 + peak.y - house.scale_height);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2i(peak.x + house.scale_width / 8, 10 + peak.y - house.scale_height);
	glVertex2i(peak.x + house.scale_width / 8, 10 + peak.y - house.scale_height / 1.5);
	glVertex2i(peak.x - house.scale_width / 8, 10 + peak.y - house.scale_height / 1.5);
	glVertex2i(peak.x - house.scale_width / 8, 10 + peak.y - house.scale_height);
	glEnd();
	//Window
	glBegin(GL_POLYGON);
	glColor3ub(house.window_r, house.window_g, house.window_b);
	glVertex2i(peak.x + house.scale_width / 16, peak.y - house.scale_height / 2);
	glVertex2i(peak.x + house.scale_width / 16, peak.y - house.scale_height / 3);
	glVertex2i(peak.x + house.scale_width / 16 + house.scale_width / 8, peak.y - house.scale_height / 3);
	glVertex2i(peak.x + house.scale_width / 16 + house.scale_width / 8, peak.y - house.scale_height / 2);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2i(peak.x + house.scale_width / 16, peak.y - house.scale_height / 2);
	glVertex2i(peak.x + house.scale_width / 16, peak.y - house.scale_height / 3);
	glVertex2i(peak.x + house.scale_width / 16 + house.scale_width / 8, peak.y - house.scale_height / 3);
	glVertex2i(peak.x + house.scale_width / 16 + house.scale_width / 8, peak.y - house.scale_height / 2);
	glEnd();
	glFlush();
}

void setWindow(float left, float right, int bottom, int top) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void createHouses() {
	int endX = WINDOW_WIDTH / ROWS;
	int endY = WINDOW_HEIGHT / COLUMNS;
	for (int rows = 0; rows < ROWS; rows++) {
		for (int columns = 0; columns < COLUMNS; columns++) {
			if (dinoX > rows * (WINDOW_WIDTH / ROWS) && dinoX < endX) {
				if (dinoY > columns * (WINDOW_HEIGHT / COLUMNS) && dinoY < endY) {
					printf("\n CRUSH");
					houses[rows][columns].scale_height = 20;
				}
			}
			glViewport(rows * (WINDOW_WIDTH / ROWS), columns * (WINDOW_HEIGHT / COLUMNS), WINDOW_WIDTH / ROWS, WINDOW_HEIGHT / COLUMNS);
			parameterizedHouse(houses[rows][columns]);
		
			endY = endY + WINDOW_HEIGHT / COLUMNS;
		}
		endY = WINDOW_HEIGHT / COLUMNS;
		endX = endX + WINDOW_WIDTH / ROWS;
	}
}

void createDino(const char* fileName, int shiftX, int shiftY) {
	glClear(GL_COLOR_BUFFER_BIT); //clears the screen
	createHouses();
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	fstream inStream;
	inStream.open(fileName, ios::in); //open the file

	if (inStream.fail()) return;

	GLint numpolys, numLines, x, y;
	inStream >> numpolys; //read the number of polylines
	glColor3ub(0, 0, 0);
	for (int j = 0; j < numpolys; j++) { //read each polyline
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < numLines; i++) {
			inStream >> x >> y; //read the next x, y pair
			glVertex2i(shiftX + x / 5, shiftY + y / 5);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

void moveDino(unsigned char keystroke, int x, int y) {
	printf("\n dinoX: %d", dinoX);
	printf("\n dinoY: %d", dinoY);
	switch (keystroke) {
	case 'w': //up
		dinoY++;
		break;

	case 's': //down
		dinoY--;
		break;

	case 'a': //left
		dinoX--;
		break;

	case 'd': //right
		dinoX++;
		break;
	}
	createDino("C:\\Users\\Russell Reding\\source\\repos\\dinosaur\\dino.dat", dinoX, dinoY);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	setWindow(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
	generateHouses(WINDOW_WIDTH, (WINDOW_HEIGHT / 2));
	createHouses();
	createDino("C:\\Users\\Russell Reding\\source\\repos\\dinosaur\\dino.dat", dinoX, dinoY);
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glPointSize(14.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 640) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 480) / 2);
	glutCreateWindow("Dinosaur and Houses");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(moveDino);
	glutMainLoop();

	return(0);

}