#pragma once
#include "GLUTCallbacks.h"
#include "Cube.h"
#include "MeshObject.h"
#include "Pyramid.h"
#include "MeshLoader.h"
#include "OBJLoader.h"
#define REFRESHRATE 16


class HelloGL
{
	public:
		HelloGL(int argc, char* argv[]);
		~HelloGL(void);

		void initObjects();
		void initGL(int argc, char* argv[]);
		void initLighting();

		void Display();
		void Update(); 
		void Keyboard(unsigned char key, int x, int y);
		void DrawString(const char* text, Vector3* position, Color* color);
		

	private:
		float rotation; 
		Camera* camera;
		SceneObject* objects[1000];
		int objectViewed;

		Vector4* _lightPosition;
		Lighting* _lightData;

};