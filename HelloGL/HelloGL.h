#pragma once
#include <Windows.h> //Required for OpenGL on Windows 
#include <gl/GL.h> //OpenGL 
#include <gl/GLU.h> //OpenGL Utilities 
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"

#define REFRESHRATE 16
class HelloGL
{
	public:
		HelloGL(int argc, char* argv[]);
		~HelloGL(void);

		void Display();
		void DrawPolygon();
		void Update(); 
		void Keyboard(unsigned char key, int x, int y);

	private:
		float rotation; 
};