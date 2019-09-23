#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <Windows.h>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

void init(void);
void display(void);
void reshape(int w, int h);
void drawShape(void);
void drawBezier(void);

#define INTERVAL 31
int stage = 0;
GLfloat bezierPoints[INTERVAL] = {0};

GLfloat ctrlpoints[4][3] = {
		{ -5.0, -2.0, 0.0}, { -6.0, 4.0, 0.0},
		{3.0, 4.0, 0.0}, {7.0, -2.0, 0.0} };

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
}

void display(void) {
	int i;
	for (i = 0; i < INTERVAL; i++) {
		bezierPoints[i] = (GLfloat) i / INTERVAL;
	}
	while (true) {
		if (stage > INTERVAL) {
			stage = 0;
		}
		drawShape();
		drawBezier();
		stage++;
		std::this_thread::sleep_for(0.1s);
	}	
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-5.0, 5.0, -5.0 * (GLfloat)h / (GLfloat)w,
			5.0 * (GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0 * (GLfloat)w / (GLfloat)h,
			5.0 * (GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawShape() {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < 4; i++)
		glVertex3fv(&ctrlpoints[i][0]);
	glEnd();
	glPointSize(100.0);
	glBegin(GL_POINT);
	for (i = 0; i < 4; i++)
		glVertex3fv(&ctrlpoints[i][0]);
	glEnd();
	glFlush();
}

void drawBezier() {
	int i;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < stage; i++) {
		glEvalCoord1f(bezierPoints[i]);
	}
	glEnd();
	glFlush();
}