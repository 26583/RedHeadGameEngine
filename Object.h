#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp> 
#include <glm/gtc/matrix_transform.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <string>
#include "Math.h"
#include <vector>
#include "Loader.h"
#include "Mesh.h"
#include "Material.h"
#pragma once
class Object
{
public:
	Object(const char* ModelFile, Material* material);
	~Object();
	void ShaderInit();
	void AttributeInit();
	void Draw();
	void CreateMatrix();
	void SetPosition(glm::vec3 position);
	glm::mat4 GetMVP();
	void IndexVBO();
	void MakeTexture();
private:
	unsigned int shaderProgram;
	unsigned int VAO;
	Math::Transform transform;
	glm::mat4 mvp;
	GLuint ProgramID;
	GLuint MatrixID;
	GLuint texture;
	GLuint TextureID;
	GLuint ModelM;
	Mesh* mesh;
	Material* material;
};

