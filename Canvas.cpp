#include "Canvas.h"

Canvas::Canvas()
{
    //triangle = Object();
}

Canvas::~Canvas()
{
}
Object* triangle = 0;
void Canvas::Draw(sf::Window* window)
{
    //Object* triangle = 0;
    if (triangle == 0) {
        triangle = new Object();
    }
    triangle->Draw();
    /*
    float vertices[] = {
    -0.5f, -0.2f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

    //CREATE VERTEX SHADER
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    //COMPILE VERTEX SHADER
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
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
    unsigned int shaderProgram;
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

    //CREATE VERTEX ATTRIBUTE BUFFER
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    //CREATE VERTEX BUFFER
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //VERTEX INTERPRET INSTRUCTIONS
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //USE THE SHADER
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    */
}
