#include "Math.h"
#include "Math.h"

glm::mat4 Math::CreateModelMatrix(glm::vec3 position, glm::vec3 size)
{
	glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3(position));
	glm::mat4 ScaleMatrix = glm::scale(glm::vec3(size));
	glm::mat4 RotationMatrix = glm::rotate(0.f, glm::vec3(0.0f, 10.0f, 0.0f));
	return TranslationMatrix * RotationMatrix * ScaleMatrix;
}

glm::mat4 Math::CreateMVP()
{
    glm::mat4 Model = glm::mat4(1.0f);
    glm::mat4 View = glm::lookAt(
        glm::vec3(0, 3.f, 5.0f), // Camera is at (4,3,3), in World Space
        glm::vec3(0, 0, 0), // and looks at the origin
        glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
    glm::mat4 projectionMatrix = glm::perspective(
        glm::radians(90.0f), // The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
        800 / 800.0f,       // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
        1.0f,              // Near clipping plane. Keep as big as possible, or you'll get precision issues.
        100.0f             // Far clipping plane. Keep as little as possible.
    );
	return projectionMatrix * View * Model;
}
