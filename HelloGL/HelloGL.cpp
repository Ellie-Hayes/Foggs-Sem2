#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	initGL(argc, argv);
	initObjects();
	initLighting();

	glutMainLoop(); 
}

void HelloGL::initObjects()
{
	camera = new Camera();
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	//Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");

	Mesh* bearMesh = OBJLoader::Load((char*)"Models/EllieBear.obj");
	Mesh* roomMesh = OBJLoader::Load((char*)"Models/Room.obj");

	Texture2D* texture = new Texture2D();
	texture->Load((char*)"Penguins.raw", 512, 512);

	Texture2D* starTex = new Texture2D();
	starTex->Load((char*)"stars.raw", 512, 512);

	Texture2D* bearTex = new Texture2D();
	bearTex->Load((char*)"beige.bmp", 300, 300);

	for (int i = 0; i < 200; i++)
	{
		objects[i] = new Cube(bearMesh, bearTex, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f, "Beary cute");
	}
	for (int i = 200; i < 400; i++)
	{
		objects[i] = new Cube(cubeMesh, starTex, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f, "Cuba");
	}
	
	objects[399] = new MeshObject(roomMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f, "Room");

	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -35.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	rotation = 0.0f;
	objectViewed = 0; 
}

void HelloGL::initGL(int argc, char* argv[])
{
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
	
	glEnable(GL_TEXTURE_2D); // without this you will just get white boxes
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glCullFace(GL_BACK);

	glMatrixMode(GL_MODELVIEW);

	

}

void HelloGL::initLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->Ambient.x = 0.9;
	_lightData->Ambient.y = 0.9;
	_lightData->Ambient.z = 0.9;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.9;
	_lightData->Specular.y = 0.9;
	_lightData->Specular.z = 0.9;
	_lightData->Specular.w = 1.0;

}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene
	glClearColor(117, 170, 255, 1);
	for (int i = 0; i < 400; i++)
	{
		glPushMatrix();
		objects[i]->Draw();
		glPopMatrix();
	}

	Vector3 v = { -1.4f, 0.7f, -1.0f };
	Color c = { 0.0f, 1.0f, 0.0f };
	DrawString("Text test slay", &v, &c);
	
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
	
}

void HelloGL::Update()
{

	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.x));

	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));


	for (int i = 0; i < 400; i++)
	{
		objects[i]->Update();
	}
	
	glutPostRedisplay();
	
	
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w': {
			camera->eye.z--;
			break;
		}

		case 'a': {
			camera->eye.x++;
			break;
		}

		case 's': {
			camera->eye.z++;
			break;
		}

		case 'd': {
			camera->eye.x--;
			break;
		}
		case 'n': { //Next
			objectViewed++;
			camera->eye.x = objects[objectViewed]->GetPosition().x; camera->eye.y = objects[objectViewed]->GetPosition().y; camera->eye.z = objects[objectViewed]->GetPosition().z;
			break;
		}
		case 'b': { //Back
			objectViewed--;
			camera->eye.x = objects[objectViewed]->GetPosition().x; camera->eye.y = objects[objectViewed]->GetPosition().y; camera->eye.z = objects[objectViewed]->GetPosition().z;
			break;
		}
	}
}

void HelloGL::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();
	glColor3f(color->r, color->g, color->b);
	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);
	glPopMatrix();
}




HelloGL::~HelloGL(void)
{
	delete camera;
}


