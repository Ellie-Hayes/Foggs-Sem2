#pragma once
#include <Windows.h> //Required for OpenGL on Windows 
#include <gl/GL.h> //OpenGL 
#include <gl/GLU.h> //OpenGL Utilities 
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"

#define REFRESHRATE 16
struct Vector3
{
	float x;
	float y;
	float z;
};

struct Camera
{
	Vector3 eye;
	Vector3 center; 
	Vector3 up; 
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z; 
};

class HelloGL
{
	public:
		HelloGL(int argc, char* argv[]);
		~HelloGL(void);

		void Display();
		void DrawPolygon();
		void DrawCube();
		void DrawCubeArray();
		void DrawObjects();
		void Update(); 
		void Keyboard(unsigned char key, int x, int y);

	private:
		float rotation; 
		Camera* camera;

		static Vertex vertices[];
		static Color colors[];

};