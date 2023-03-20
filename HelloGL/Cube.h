#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include <iostream>
#include <fstream>

class Cube
{
public:
	Cube(Mesh* _mesh, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
	void SetRotation(float rotation);
	/*static bool Load(char* path);*/

private:
	/* static Vertex* indexedVertices;
	 static Color* indexedColors;
	 static GLushort* indices;
	 static int numVertices, numColors, numIndices;*/

	Mesh* mesh;
	Vector3 _position; 
	float _rotation;
	
};

