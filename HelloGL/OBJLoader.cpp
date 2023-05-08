#include "OBJLoader.h"
using namespace std;

namespace OBJLoader
{
    void LoadVertices(std::istringstream& iss, Mesh& mesh);
    void LoadTexCoords(std::istringstream& iss, Mesh& mesh);
    void LoadNormals(std::istringstream& iss, Mesh& mesh);
    void LoadIndices(std::istringstream& iss, Mesh& mesh);

    void LoadVertices(std::istringstream& iss, Mesh& mesh)
    {
        mesh.VertexCount++;

        Vertex* newVertices = new Vertex[mesh.VertexCount];

        for (int i = 0; i < mesh.VertexCount - 1; i++)
            newVertices[i] = mesh.Vertices[i];

        iss >> newVertices[mesh.VertexCount - 1].x;
        iss >> newVertices[mesh.VertexCount - 1].y;
        iss >> newVertices[mesh.VertexCount - 1].z;

        //std::cout << newVertices[mesh.VertexCount - 1].x << " " << newVertices[mesh.VertexCount - 1].y << " " << newVertices[mesh.VertexCount - 1].z << endl;

        delete[] mesh.Vertices;
        mesh.Vertices = newVertices;
    }

    void LoadTexCoords(std::istringstream& iss, Mesh& mesh)
    {
        mesh.TexCoordCount++;

        TexCoord* newTexCoords = new TexCoord[mesh.TexCoordCount];

        for (int i = 0; i < mesh.TexCoordCount - 1; i++)
            newTexCoords[i] = mesh.TexCoords[i];

        iss >> newTexCoords[mesh.TexCoordCount - 1].u;
        iss >> newTexCoords[mesh.TexCoordCount - 1].v;

        //std::cout << newTexCoords[mesh.TexCoordCount - 1].u << " " << newTexCoords[mesh.TexCoordCount - 1].v << endl;

        delete[] mesh.TexCoords;
        mesh.TexCoords = newTexCoords;
    }

    void LoadNormals(std::istringstream& iss, Mesh& mesh)
    {
        mesh.NormalCount++;

        Vector3* newNormals = new Vector3[mesh.NormalCount];

        for (int i = 0; i < mesh.NormalCount - 1; i++)
            newNormals[i] = mesh.Normals[i];

        iss >> newNormals[mesh.NormalCount - 1].x;
        iss >> newNormals[mesh.NormalCount - 1].y;
        iss >> newNormals[mesh.NormalCount - 1].z;

        //std::cout << newNormals[mesh.NormalCount - 1].x << " " << newNormals[mesh.NormalCount - 1].y << " " << newNormals[mesh.NormalCount - 1].z << endl;

        delete[] mesh.Normals;
        mesh.Normals = newNormals;
    }

    void LoadIndices(std::istringstream& iss, Mesh& mesh)
    {
        mesh.IndexCount += 3;

        GLushort* newIndices = new GLushort[mesh.IndexCount];

        for (int i = 0; i < mesh.IndexCount - 3; i++)
            newIndices[i] = mesh.Indices[i];

        std::string vertexString;
        for (int i = mesh.IndexCount - 3; i < mesh.IndexCount; i++)
        {
            std::getline(iss, vertexString, '/');
            newIndices[i] = std::stoi(vertexString) - 1;
            //std::cout << newIndices[i] << " ";

            // skip the second and third indices
            std::getline(iss, vertexString, '/');
            std::getline(iss, vertexString, ' ');
        }

        //std::cout << std::endl;

        delete[] mesh.Indices;
        mesh.Indices = newIndices;
    }
    

    Mesh* OBJLoader::Load(char* path)
    {
        Mesh* mesh = new Mesh();
        mesh->IndexCount = 0; 

        std::ifstream inFile(path);

        if (!inFile.good())
        {
            std::cerr << "Can't open mesh file " << path << std::endl;
            delete mesh;
            return nullptr;
        }

        std::string line;

        while (std::getline(inFile, line))
        {
            std::istringstream iss(line);
            std::string prefix;
            iss >> prefix;

            if (prefix == "v")
                LoadVertices(iss, *mesh);
            else if (prefix == "vn")
                LoadNormals(iss, *mesh);
            else if (prefix == "vt")
                LoadTexCoords(iss, *mesh);
            else if (prefix == "f")
                LoadIndices(iss, *mesh);
        }

        inFile.close();

        std::cout << path << " loaded " << std::endl; 
        return mesh;
    }
   
}