#pragma once

#ifndef _Cube
#define _Cube

#include "SceneObject.h"
#include "Structures.h"
#include <iostream>
#include <fstream>

class Cube : public SceneObject
{
public:
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z, std::string name);
	~Cube();

	void Draw();
	void Update();
	void SetRotation(float rotation);
	

private:
	
	float _rotation;
	Material* _material; 
	
};

#endif
