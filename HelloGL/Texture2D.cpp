#include "Texture2D.h"

using namespace std;

Texture2D::Texture2D()
{
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
	char* tempTextureData;
	int fileSize; 
	std::ifstream inFile;

	_width = width; _height = height; 
	inFile.open(path, ios::binary);

	if (!inFile.good())
	{
		std::cerr << "Can't open texture file " << path << std::endl;
		return false;
	}

	inFile.seekg(0, ios::end); // Go to the end of the file
	fileSize = (int)inFile.tellg(); //Tells us current position of file which is the end = how many characters in the file
	tempTextureData = new char[fileSize]; // Create data array
	inFile.seekg(0, ios::beg); 
	inFile.read(tempTextureData, fileSize);
	inFile.close();

	cout << path << " loaded" << endl; 

	glGenTextures(1, &_ID);
	glBindTexture(GL_TEXTURE_2D, _ID);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);

	delete[] tempTextureData;
	return true; 
}
