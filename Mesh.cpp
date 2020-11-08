#include "Mesh.h"

Mesh::Mesh(const char* _model, Math::Transform* _transform, Material* _material)
{
	bool res = loadOBJ(_model, vertices, uvs, normals);
	transform = _transform;
    AttributeInit();
    material = _material;
}

void Mesh::AttributeInit()
{
    //CREATE VERTEX ATTRIBUTE BUFFER
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,                  // attribute
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glVertexAttribPointer(
        1,                                // attribute
        2,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );
}

void Mesh::CreateMatrix()
{
    glMatrixMode(GL_PROJECTION);
    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3(transform->position));
    glm::mat4 ScaleMatrix = glm::scale(glm::vec3(transform->size));
    glm::mat4 RotationMatrix = glm::rotate(0.f, glm::vec3(0.0f, 10.0f, 0.0f));
    glm::mat4 ModelMatrix = TranslationMatrix * RotationMatrix * ScaleMatrix;

    //HERE COMES THE MVP!!!
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
    mvp = projectionMatrix * View * Model * ModelMatrix;

    // GLuint MatrixID = glGetUniformLocation(0, "MVP");
    MatrixID = glGetUniformLocation(material->GetShaderProgram(), "MVP");
}

void Mesh::Render()
{
    AttributeInit();
    material->Use();
    CreateMatrix();
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
