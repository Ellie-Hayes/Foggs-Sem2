#include "Cube.h"


Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z, std::string name) : SceneObject(mesh)
{
	_texture = texture;
	_rotation = rand() % 360;

	_position.x = x;
	_position.y = y;
	_position.z = z; 

	_material = new Material();
	_material->Ambient.x = 0.3; _material->Ambient.y = 0.4; _material->Ambient.z = 0.3;
	_material->Ambient.w = 1.0;
	_material->Diffuse.x = 1.0; _material->Diffuse.y = 1.0; _material->Diffuse.z = 1.0;
	_material->Diffuse.w = 1.0;
	_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	_material->Shininess = 100.0f;

	_nameText = name.c_str();

}

Cube::~Cube()
{

}

void Cube::Draw()
{
	Vector3 v = { _position.x, _position.y + 10, _position.z };
	Color c = { 0.0f, 1.0f, 0.0f };

	DrawString("Cube", &v, &c);

	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glScalef(1, 1, 1);
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 0.0f, 1.0f, 0.0f);
		
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);

		glEnable(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);

		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
		glPushMatrix();
		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		
		
		glTranslatef(0, 0, 0);

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

