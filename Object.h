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
#include "shader.h"
#pragma once
class Object
{
public:
	Object();
	~Object();
	void ShaderInit();
	void AttributeInit();
	void Draw();
	void CreateMatrix();
	glm::mat4 GetMVP();
private:
	unsigned int shaderProgram;
	unsigned int VAO;
	Vector3 transform = Vector3(0,0,0);
	glm::mat4 mvp;
	GLuint ProgramID;
	GLuint MatrixID;
};

