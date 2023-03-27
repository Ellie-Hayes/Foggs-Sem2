#pragma once

#include "SceneObject.h"
#include "Structures.h"

class Pyramid : public SceneObject
{
public:
	Pyramid(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Pyramid();

	void Draw();
	void Update();

private:
	Vector3 _position;
};

