#pragma once
#ifndef _OBJLoader
#define _OBJLoader

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#ifndef _hStructs
#include "Structures.h"
#endif
namespace OBJLoader
{
	Mesh* Load(char* path);
};

#endif