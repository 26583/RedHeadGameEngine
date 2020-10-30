#include "Object.h"

const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout(location = 1) in vec2 vertexUV;\n"
"out vec2 UV;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* MatrixShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout(location = 1) in vec2 vertexUV;\n"
"out vec2 UV;\n"
"uniform mat4 MVP;\n"
"void main()\n"
"{\n"
"   gl_Position =  MVP * vec4(aPos,1);\n"
"   UV = vertexUV;\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"in vec2 UV;\n"
"out vec4 FragColor;\n"
"uniform sampler2D myTextureSampler;\n"
"void main()\n"
"{\n"
"   FragColor = texture( myTextureSampler, UV ).rgb;\n"
"}\n\0";

Object::Object()
{
    //ShaderInit();
    shaderProgram = LoadShaders("SimpleVertexShader.vertexshader", "SimpleColor.fragmentshader");
    AttributeInit();
    CreateMatrix();
    texture = loadBMP_custom("textures/Grass.bmp");
    TextureID = glGetUniformLocation(shaderProgram, "myTextureSampler");

}

Object::~Object()
{
}
/*
float vertices[] = {
   1.000000, 1.000000, - 1.000000,
 - 1.000000, 1.000000, - 1.000000,
 - 1.000000, 1.000000, 1.000000,
   1.000000, 1.000000, 1.000000,
   1.000000, - 1.000000, 1.000000,
 - 1.000000, - 1.000000, 1.000000,
 - 1.000000, - 1.000000, - 1.000000,
   1.000000, - 1.000000, - 1.000000
};
int indices[] = {
      1, 3, 0,
      3, 5, 4,
      2, 6, 5,
      7, 5, 6,
      0, 4, 7,
      1, 7, 6,
      1, 2, 3,
      3, 2, 5,
      2, 1, 6,
      7, 4, 5,
      0, 3, 4,
      1, 0, 7
};
int uv_indices[] = {
    0, 1, 2,
    3, 4, 5,
    6, 7, 8,
    9, 10, 11,
    12, 13, 14,
    15, 16, 17,
    0, 18, 1,
    3, 19, 4,
    6, 20, 7,
    9, 21, 10,
    12, 22, 13,
    15, 23, 16
};
float uv_vetices[] = {
 0.003677, 0.502101,
 0.497911, 0.502101,
 0.497911, 0.996336,
 0.003677, 0.996336,
 0.994113, 0.504679,
 0.994113, 0.996680,
 0.505934, 0.996680,
 0.505934, 0.504679,
 0.993753, 0.499107,
 0.993753, 0.996971,
 0.499756, 0.996971,
 0.499756, 0.499107,
 0.007919, 0.006269,
 0.495303, 0.006269,
 0.495303, 0.493653,
 0.007919, 0.493653,
 0.996919, 0.500728,
 0.996919, 1.000419,
 0.501109, 1.000419,
 0.501109, 0.500728,
 0.991238, 0.503259,
 0.991238, 0.996100,
 0.502225, 0.996100,
 0.502225, 0.503259
};
*/
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

std::vector< glm::vec3 > vertices;
std::vector< glm::vec2 > uvs;
std::vector< glm::vec3 > normals; // Won't be used at the moment.
bool res = loadOBJ("models/minecube.obj", vertices, uvs, normals);


void Object::AttributeInit()
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



void Object::Draw()
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //printf("draw");
    rotY += 0.02f;
    CreateMatrix();
    AttributeInit();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    // Set our "myTextureSampler" sampler to use Texture Unit 0
    glUniform1i(TextureID, 0);
    //USE THE SHADER
    glUseProgram(shaderProgram);  //SET MATRIXES
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);
    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void Object::CreateMatrix()
{
    glMatrixMode(GL_PROJECTION);
    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3(transform.pos.x, transform.pos.y, transform.pos.z));
    glm::mat4 ScaleMatrix = glm::scale(glm::vec3(transform.size.x, transform.size.y, transform.size.z));
    glm::mat4 RotationMatrix = glm::rotate(rotY, glm::vec3(0.0f,10.0f,0.0f));
    glm::mat4 ModelMatrix = TranslationMatrix * RotationMatrix * ScaleMatrix;

    //HERE COMES THE MVP!!!
    glm::mat4 Model = glm::mat4(1.0f);
    glm::mat4 View = glm::lookAt(
        glm::vec3(0, 1.5f, 5.0f), // Camera is at (4,3,3), in World Space
        glm::vec3(0, 0, 0), // and looks at the origin
        glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
    glm::mat4 projectionMatrix = glm::perspective(
        glm::radians(90.0f), // The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
        800.0f / 800.0f,       // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
        1.0f,              // Near clipping plane. Keep as big as possible, or you'll get precision issues.
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
