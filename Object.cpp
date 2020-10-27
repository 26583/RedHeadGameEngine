#include "Object.h"

const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* MatrixShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 MVP;\n"
"void main()\n"
"{\n"
"   gl_Position =  MVP * vec4(aPos,1);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

Object::Object()
{
    ShaderInit();
    AttributeInit();
    CreateMatrix();
}

Object::~Object()
{
}

float vertices[] = {
    -0.5f, -0.5f, 0.5f,
     0.5f, -0.5f, 0.5f,
     0.5f,  0.5f, 0.5f,
     -0.5f,  0.5f, 0.5f,
     -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     -0.5f,  0.5f, -0.5f
};
int indices[] = {
    0,1,2,
    0,2,3,

    1,4,6,
    1,6,5,

    0,4,5,
    0,5,1,

    3,7,6,
    3,6,2,

    4,7,6,
    4,5,6,

    0,3,7,
    0,7,4
};
float rotY = 0.0f;


void Object::ShaderInit()
{
    //CREATE VERTEX SHADER
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    //COMPILE VERTEX SHADER
    glShaderSource(vertexShader, 1, &MatrixShaderSource, NULL);
    glCompileShader(vertexShader);

    //ERROR HANDLELING
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //CREATE FRAG SHADER
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //CREATE SHADER PROGRAM
    //unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //DELETE SHADERS
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Object::AttributeInit()
{
    //CREATE VERTEX ATTRIBUTE BUFFER
    glGenVertexArrays(1, &VAO);

    //CREATE VERTEX BUFFER
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //CREATE ELEMENTBUFFER
    GLuint elementbuffer;
    glGenBuffers(1, &elementbuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);


    //VERTEX INTERPRET INSTRUCTIONS
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Object::Draw()
{
    rotY += 0.02f;
    //USE THE SHADER
    glUseProgram(shaderProgram);

    //SET MATRIXES
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);
    glBindVertexArray(VAO);
    glDrawElements(
        GL_TRIANGLES,      // mode
        sizeof(indices),    // count
        GL_UNSIGNED_INT,   // type
        (void*)0           // element array buffer offset
    );
}

void Object::CreateMatrix()
{
    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3(transform.pos.x, transform.pos.y, transform.pos.z));
    glm::mat4 ScaleMatrix = glm::scale(glm::vec3(transform.size.x, transform.size.y, transform.size.z));
    glm::mat4 RotationMatrix = glm::rotate(rotY, glm::vec3(0.0f,10.0f,0.0f));
    glm::mat4 ModelMatrix = TranslationMatrix * RotationMatrix * ScaleMatrix;

    //HERE COMES THE MVP!!!
    glm::mat4 Model = glm::mat4(1.0f);
    glm::mat4 View = glm::lookAt(
        glm::vec3(0, 1.5f, 1.5f), // Camera is at (4,3,3), in World Space
        glm::vec3(0, 0, 0), // and looks at the origin
        glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
    glm::mat4 projectionMatrix = glm::perspective(
        glm::radians(90.0f), // The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
        800.0f / 800.0f,       // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
        0.1f,              // Near clipping plane. Keep as big as possible, or you'll get precision issues.
        100.0f             // Far clipping plane. Keep as little as possible.
    );
    mvp = projectionMatrix * View * Model * ModelMatrix;

   // GLuint MatrixID = glGetUniformLocation(0, "MVP");
    MatrixID = glGetUniformLocation(shaderProgram, "MVP");
}

glm::mat4 Object::GetMVP()
{
    return mvp;
}
