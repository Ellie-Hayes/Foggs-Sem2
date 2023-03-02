#include "HelloGL.h"
Vertex HelloGL::vertices[] = { 1, 1, 1,  -1, 1, 1,  -1,-1, 1,      // v0-v1-v2 (front)
				-1,-1, 1,   1,-1, 1,   1, 1, 1,      // v2-v3-v0

				1, 1, 1,   1,-1, 1,   1,-1,-1,      // v0-v3-v4 (right)
				1,-1,-1,   1, 1,-1,   1, 1, 1,      // v4-v5-v0

				1, 1, 1,   1, 1,-1,  -1, 1,-1,      // v0-v5-v6 (top)
				-1, 1,-1,  -1, 1, 1,   1, 1, 1,      // v6-v1-v0

				-1, 1, 1,  -1, 1,-1,  -1,-1,-1,      // v1-v6-v7 (left)
				-1,-1,-1,  -1,-1, 1,  -1, 1, 1,      // v7-v2-v1

				-1,-1,-1,   1,-1,-1,   1,-1, 1,      // v7-v4-v3 (bottom)
				1,-1, 1,  -1,-1, 1,  -1,-1,-1,      // v3-v2-v7

				1,-1,-1,  -1,-1,-1,  -1, 1,-1,      // v4-v7-v6 (back)
				-1, 1,-1,   1, 1,-1,   1,-1,-1 };    // v6-v5-v4

Color HelloGL::colors[] = { 1, 1, 1,   1, 1, 0,   1, 0, 0,      // v0-v1-v2 (front)
				1, 0, 0,   1, 0, 1,   1, 1, 1,      // v2-v3-v0

				1, 1, 1,   1, 0, 1,   0, 0, 1,      // v0-v3-v4 (right)
				0, 0, 1,   0, 1, 1,   1, 1, 1,      // v4-v5-v0

				1, 1, 1,   0, 1, 1,   0, 1, 0,      // v0-v5-v6 (top)
				0, 1, 0,   1, 1, 0,   1, 1, 1,      // v6-v1-v0

				1, 1, 0,   0, 1, 0,   0, 0, 0,      // v1-v6-v7 (left)
				0, 0, 0,   1, 0, 0,   1, 1, 0,      // v7-v2-v1

				0, 0, 0,   0, 0, 1,   1, 0, 1,      // v7-v4-v3 (bottom)
				1, 0, 1,   1, 0, 0,   0, 0, 0,      // v3-v2-v7

				0, 0, 1,   0, 0, 0,   0, 1, 0,      // v4-v7-v6 (back)
				0, 1, 0,   0, 1, 1,   0, 0, 1 };    // v6-v5-v4

Vertex HelloGL::indexedVertices[] = { 1, 1, 1,  -1, 1, 1,  // v0,v1,
				-1,-1, 1,   1,-1, 1,   // v2,v3
				1,-1,-1,   1, 1,-1,    // v4,v5
				-1, 1,-1,   -1,-1,-1 }; // v6,v7

Color HelloGL::indexedColors[] = { 1, 1, 1,   1, 1, 0,   // v0,v1,
				1, 0, 0,   1, 0, 1,   // v2,v3
				0, 0, 1,   0, 1, 1,   // v4,v5
				0, 1, 0,   0, 0, 0 }; //v6,v7

GLushort HelloGL::indices[] = { 0, 1, 2,  2, 3, 0,      // front
				0, 3, 4,  4, 5, 0,      // right
				0, 5, 6,  6, 1, 0,      // top
				1, 6, 7,  7, 2, 1,      // left
				7, 4, 3,  3, 2, 7,      // bottom
				4, 7, 6,  6, 5, 4 };    // back


// chnage camera need to change eye and center crazyyyyy!!
HelloGL::HelloGL(int argc, char* argv[])
{
	camera = new Camera();

	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	rotation = 0.0f; 
	GLUTCallbacks::Init(this);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Simple OpenGL Program");

	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000); // Field of view, Aspect Ratio, Near clipping distance, Far clipping distance. 
	glTranslatef(0.0f, 0.0f, -5.0f);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);

	glutMainLoop(); 
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
	glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, -1.0f);


	//DrawCubeArray();
	//DrawIndexedCube(); 
	DrawCubeArrayAlt();
	//DrawIndexedCubeAlt();

	glPopMatrix();
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
	//DrawPolygon();
	//DrawObjects();
}

void HelloGL::Update()
{
	glLoadIdentity();
	if (rotation >= 360.0f) { rotation = 0.0f; }
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);


	glutPostRedisplay();
	
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		rotation += 2.0f;
	}
	else if (key == 'a')
	{
		rotation += -2.0f;
	}
	if (key == 'w')
	{
		camera->eye.x += 0.8f;
	}
	if (key == 's')
	{
		camera->eye.x -= 0.8f;
	}

}

void HelloGL::DrawIndexedCube()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3f(indexedColors[indices[i]].r, indexedColors[indices[i]].g, indexedColors[indices[i]].b);
		glVertex3f(indexedVertices[indices[i]].x, indexedVertices[indices[i]].y, indexedVertices[indices[i]].z);
		
	}
	glEnd();

	glPopMatrix();


}

void HelloGL::DrawPolygon()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 1.0f, 0.0f, -1.0f);

	glBegin(GL_POLYGON); //starts to draw a polygon
	glColor4f(0.8f, 0.0f, 0.0f, 0.0f);
	glVertex2f(-0.9, 0.0); //next point, top right
	glVertex2f(-0.5, 0.8); 
	glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
	glVertex2f(0.5, 0.8);
	glVertex2f(0.9, 0.0);
	glColor4f(0.0f, 0.5f, 0.5f, 0.0f);
	glVertex2f(0.5, -0.8);
	glVertex2f(-0.5, -0.8);


	glEnd(); // defines the end of the draw

	glPopMatrix();
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
}

void HelloGL::DrawCube()
{
	glBegin(GL_TRIANGLES);
	// face v0-v1-v2
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	// face v2-v3-v0
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// face v0-v3-v4
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	// face v4-v5-v0
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// face v0-v5-v6
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	// face v6-v1-v0
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// face  v1-v6-v7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	// face v7-v2-v1
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);

	// face v7-v4-v3
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	// face v3-v2-v7
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);

	// face v4-v7-v6
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	// face v6-v5-v4
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	glEnd();

}

void HelloGL::DrawCubeArray()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&colors[i].r);
		glVertex3fv(&vertices[i].x);
	}
	glEnd();

	glPopMatrix();

}

void HelloGL::DrawCubeArrayAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glPushMatrix();
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void HelloGL::DrawIndexedCubeAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);

	glPushMatrix();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}



void HelloGL::DrawObjects()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene

	glPushMatrix();
	//glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 1.0f, 0.0f, -1.0f);
	
	
	glutWireTeapot(1);


	glPopMatrix();
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
}



HelloGL::~HelloGL(void)
{
	delete camera;
}

