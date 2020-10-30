#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Window.h"
#include <string>
#include <iostream>
Window* w;
int main()
{
    w = new Window();
    w->MakeWindow("My Window", 800, 800);
    glewInit();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_CULL_FACE);
    while (w->CheckOpen()) {
        w->PollWindow();
    }
    return 0;
}