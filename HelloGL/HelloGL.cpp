#include "HelloGL.h"


// chnage camera need to change eye and center crazyyyyy!!
HelloGL::HelloGL(int argc, char* argv[])
{
	camera = new Camera();
	for (int i = 0; i < 200; i++)
	{
		cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);

	}

	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -35.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	rotation = 0.0f; 
	GLUTCallbacks::Init(this);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Simple OpenGL Program");

	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 1, 1000); // Field of view, Aspect Ratio, Near clipping distance, Far clipping distance. 
	glTranslatef(0.0f, 0.0f, -5.0f);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glutMainLoop(); 
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Draw();
	}
	
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
	
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Update();
	}
	
	glutPostRedisplay();
	
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	/*if (key == 'd')
	{
		rotation += 2.0f;
	}*/

}


HelloGL::~HelloGL(void)
{
	delete camera;
}

