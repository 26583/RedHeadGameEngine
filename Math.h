#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp> 
#include <glm/gtc/matrix_transform.hpp>
#pragma once
namespace Math {
	struct Transform {
		glm::vec3 position;
		glm::vec3 size;
		glm::vec3 rotation;
	};

	glm::mat4 CreateModelMatrix(glm::vec3 position, glm::vec3 size);
	glm::mat4 CreateMVP();
}