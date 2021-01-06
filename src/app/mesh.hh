#pragma once
#include <vector>
#include "vertex.hh"
#include "texture.hh"

class Mesh
{
public:
    Vector position;
    Vector rotation;
    Vector scale;

    std::vector<Vertex> vertices;
    std::vector<int> indices;

    Texture *texture;

    Mesh()
    {
        position = Vector(0, 0, 0);
        rotation = Vector(0, 0, 0);
        scale = Vector(1, 1, 1);
    };

    Mesh(const char *path, const char *texturePath);

    virtual ~Mesh()
    {
        delete texture;
    };
};
