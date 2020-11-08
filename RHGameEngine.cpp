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
int main()
{
    w.MakeWindow("My Window", 800, 800);
    glewInit();
    glEnable(GL_DEPTH_TEST);
   // glDepthFunc(GL_GREATER);
    glEnable(GL_CULL_FACE);
    sceneM.AddObject(glm::vec3(0, 0, 0));
    sceneM.AddObject(glm::vec3(1,1,-1));
    while (w.CheckOpen()) {
        //Loop here
        //end draw loop
        w.PollWindow();
        sceneM.Update();
    }
    return 0;
}