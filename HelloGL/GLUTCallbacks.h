#pragma once
class HelloGL;

#include "GL\freeglut.h"
#include <iostream>

namespace GLUTCallbacks
{
	void Init(HelloGL* gl);

	void Display();

	void Timer(int preferredRefresh);

	void Keyboard(unsigned char key, int x, int y);
}
