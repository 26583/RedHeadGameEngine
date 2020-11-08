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
#include "Material.h"
#pragma once
class Mesh
{
public:
	Mesh(const char* _model, Math::Transform* _transform, Material* _material);
	~Mesh();
	void AttributeInit();
	void CreateMatrix();
	void Render();
private:
	std::vector< glm::vec3 > vertices;
	std::vector< glm::vec2 > uvs;
	std::vector< glm::vec3 > normals;
	Math::Transform* transform;
	unsigned int VAO;
	glm::mat4 mvp;
	GLuint MatrixID;
	Material* material;
};