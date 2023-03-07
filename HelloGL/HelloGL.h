#pragma once
#include <Windows.h> //Required for OpenGL on Windows 
#include <gl/GL.h> //OpenGL 
#include <gl/GLU.h> //OpenGL Utilities 
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#include "Structures.h"
#define REFRESHRATE 16


class HelloGL
{
	public:
		HelloGL(int argc, char* argv[]);
		~HelloGL(void);

		void Display();
		void DrawPolygon();
		void DrawCube();
		void DrawCubeArray();
		void DrawCubeArrayAlt();
		void DrawIndexedCubeAlt();
		void DrawObjects();
		void Update(); 
		void Keyboard(unsigned char key, int x, int y);
		void DrawIndexedCube();

	private:
		float rotation; 
		Camera* camera;

		static Vertex vertices[];
		static Color colors[];

		static Vertex indexedVertices[];
		static Color indexedColors[];
		static GLushort indices[];

};