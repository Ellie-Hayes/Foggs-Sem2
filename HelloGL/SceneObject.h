#pragma once
#ifndef _SceneObject
#define _SceneObject

#ifndef _hStructs
#include "Structures.h"
#include "Texture2D.h"
#endif


class SceneObject
{
protected:
	void DrawString(const char* text, Vector3* position, Color* color);

	Mesh* _mesh;
	Texture2D* _texture; 
	Vector3 _position;
	const char* _nameText;

public:
	SceneObject(Mesh* mesh);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
	Vector3 GetPosition() { return _position; }
};

#endif