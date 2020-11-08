#include "Material.h"

Material::Material(const char* _vertexShader, const char* _fragmentShader, const char* _texture)
{
	shaderProgram = LoadShaders(_vertexShader, _fragmentShader);
	texture = loadBMP_custom(_texture);
	TextureID = glGetUniformLocation(shaderProgram, "myTextureSampler");
}

void Material::Use()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    // Set our "myTextureSampler" sampler to use Texture Unit 0
    glUniform1i(TextureID, 0);
    //USE THE SHADER
    glUseProgram(shaderProgram);
}

unsigned int Material::GetShaderProgram()
{
    return shaderProgram;
}