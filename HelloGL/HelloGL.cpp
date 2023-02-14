#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop(); 
}

void HelloGL::Display()
{
	DrawPolygon();
}

void HelloGL::DrawPolygon()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
	glBegin(GL_POLYGON); //starts to draw a polygon
	glColor4f(0.8f, 0.0f, 0.0f, 0.0f);
	glVertex2f(0.0, 0.7); //next point, top right
	glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
	glVertex2f(0.75, -0.5); //bottom right
	glColor4f(0.0f, 0.5f, 0.5f, 0.0f);
	glVertex2f(-0.75, -0.5); //last point of the polygon, bottom left
	glEnd(); // defines the end of the draw
	glFlush(); //flushes the scene drawn to the graphics card
}



HelloGL::~HelloGL(void)
{

}

