#include "Object.h"

Object::Object(const char* ModelFile, Material* material)
{
    
    transform.size = glm::vec3(1,1,1);
    //material = new Material("SimpleVertexShader.vertexshader", "SimpleColor.fragmentshader", "textures/Grass.bmp");"models/BasicSphere.obj"
    mesh = new Mesh(ModelFile, &transform, material);
}

Object::~Object()
{
}

void Object::Draw()
{
    mesh->Render();
}



void Object::SetPosition(glm::vec3 position)
{
    transform.position = position;
}

glm::mat4 Object::GetMVP()
{
    return mvp;
}
