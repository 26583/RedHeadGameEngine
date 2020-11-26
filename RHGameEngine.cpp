#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Window.h"
#include <string>
#include <iostream>
#include "SceneManager.h"
//Window* w;
Window w;
SceneManager sceneM;
Material* material;
int main()
{
    w.MakeWindow("My Window", 800, 800);
    glewInit();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    material = new Material("SimpleVertexShader.vertexshader", "SimpleColor.fragmentshader", "textures/Grass.bmp");
    sceneM.AddObject(glm::vec3(0,0,0), "models/BasicSphere.obj",material);
    while (w.CheckOpen()) {
        //Loop here
        //end draw loop
        w.PollWindow();
        sceneM.Update();
    }
    return 0;
}