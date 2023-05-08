#pragma once
#include "Structures.h"
#include <iostream>
#include <fstream>

class Texture2D
{
public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);
	bool LoadBMP(char* path, int width, int height);

	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }


private:
	GLuint _ID; //Texture ID
	int _width, _height;

};

