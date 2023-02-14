#pragma once
#include <Windows.h> //Required for OpenGL on Windows 
#include <gl/GL.h> //OpenGL 
#include <gl/GLU.h> //OpenGL Utilities 
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"

class HelloGL
{
	public:
		HelloGL(int argc, char* argv[]);
		~HelloGL(void);

		void Display();
		void DrawPolygon();
};