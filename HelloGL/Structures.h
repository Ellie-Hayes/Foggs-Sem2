#pragma once

#ifndef _hStructs
#define _hStructs

#include <Windows.h>
#include <gl/GL.h> //OpenGL 
#include <gl/GLU.h> //OpenGL Utilities 
#include "GL\freeglut.h" //freeglut library
struct Vector3
{
	float x;
	float y;
	float z;
};

struct Vector4
{
	float x, y, z, w; // w used for matrix multiplication 
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

//struct Color
//{
//	GLfloat r, g, b;
//};

struct Vertex
{
	GLfloat x, y, z;
};

struct TexCoord
{
	GLfloat u, v;
};

struct Mesh
{
	Vertex* Vertices;
	Vector3* Normals;
	GLushort* Indices;
	TexCoord* TexCoords;

	int VertexCount, NormalCount, IndexCount, TexCoordCount;
	
};

struct Lighting
{
	Vector4 Ambient, Diffuse, Specular;
};

struct Material
{
	Vector4 Ambient, Diffuse, Specular;
	GLfloat Shininess;
};



#endif