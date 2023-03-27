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
	Mesh* _mesh;
	Texture2D* _texture; 
public:
	SceneObject(Mesh* mesh);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();

};

#endif