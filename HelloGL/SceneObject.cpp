#include "SceneObject.h"



SceneObject::SceneObject(Mesh* mesh)
{
	_mesh = mesh; 
}

SceneObject::~SceneObject()
{
}

void SceneObject::Update()
{
}

void SceneObject::Draw()
{

}

void SceneObject::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);
	glPopMatrix();
}
