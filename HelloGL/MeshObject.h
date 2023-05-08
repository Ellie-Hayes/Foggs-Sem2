#pragma once
#include "SceneObject.h"
#include "Structures.h"
#include <iostream>
#include <fstream>

class MeshObject : public SceneObject
{
public:
	MeshObject(Mesh* mesh, Texture2D* texture, float x, float y, float z, std::string name);
	~MeshObject();

	void Draw();
	void Update();
	void SetRotation(float rotation);

private:
	float _rotation;
	Material* _material;

};

