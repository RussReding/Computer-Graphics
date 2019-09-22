#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble size = 1;


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clears the screen
	glBegin(GL_POINTS); //GL_LINES, GL_POLYGON
	glVertex2i(100, 100); //draws three points
	glVertex2i(100, 200);
	glVertex2i(200, 200);
	glEnd();
	glFlush();	//send all outputs
}

void reshapeFunc(int x, int y)
{
	
}

void idleFunc(void)
{
	
}

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 1.0f, 1.0f);
	//glClearColor(red, green, blue, alpha);

	glPointSize(14.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("My First Animation");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
