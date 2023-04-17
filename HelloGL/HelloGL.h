#pragma once
#include "GLUTCallbacks.h"
#include "Cube.h"
#include "Pyramid.h"
#include "MeshLoader.h"
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

		

	private:
		float rotation; 
		Camera* camera;
		SceneObject* objects[1000];

		Vector4* _lightPosition;
		Lighting* _lightData;

};