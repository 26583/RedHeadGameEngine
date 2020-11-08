#include "Loader.h"
#include <GL/glew.h>
#pragma once
class Material
{
public:
	Material(const char* _vertexShader, const char* _fragmentShader, const char* _texture);
	~Material();
	void Use();
	unsigned int GetShaderProgram();
private:
	unsigned int shaderProgram;
	GLuint texture;
	GLuint TextureID;
};