#include "Cube.h"
//Vertex* Cube::indexedVertices = nullptr;
//Color* Cube::indexedColors = nullptr;
//GLushort* Cube::indices = nullptr;
//
//int Cube::numVertices = 0;
//int Cube::numColors = 0;
//int Cube::numIndices = 0;


Cube::Cube(Mesh* _mesh, float x, float y, float z)
{
	mesh = _mesh;
	_rotation = rand() % 360;

	_position.x = x;
	_position.y = y;
	_position.z = z; 
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	if (mesh->Vertices != nullptr && mesh->Colors != nullptr && mesh->Indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, mesh->Colors);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
		glRotatef(_rotation, 0.0f, 1.0f, 0.0f);
		glRotatef(_rotation, 0.0f, 0.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	
}

void Cube::Update()
{
	_rotation += 0.8f; 
	if (_rotation >= 360.0f) { _rotation = 0.0f; }
}

void Cube::SetRotation(float rotation)
{
	_rotation = rotation; 
}

//bool Cube::Load(char* path)
//{
//	std::ifstream inFile;
//	inFile.open(path);
//	if (!inFile.good())
//	{
//		std::cerr << "Can't open text file " << path << std::endl;
//		return false;
//	}
//
//	inFile >> numVertices;
//	indexedVertices = new Vertex[numVertices];
//	for (int i = 0; i < numVertices; i++)
//	{
//		inFile >> indexedVertices[i].x >> indexedVertices[i].y >> indexedVertices[i].z;
//	}
//
//	inFile >> numColors;
//	indexedColors = new Color[numColors];
//	for (int i = 0; i < numColors; i++)
//	{
//		inFile >> indexedColors[i].r >> indexedColors[i].g >> indexedColors[i].b;
//	}
//
//	inFile >> numIndices;
//	indices = new GLushort[numIndices];
//	for (int i = 0; i < numIndices; i++)
//	{
//		inFile >> indices[i];
//	}
//
//	inFile.close();
//
//	return true;
//}
