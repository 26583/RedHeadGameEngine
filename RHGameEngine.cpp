#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Window.h"
#include <string>
#include <iostream>

int main()
{
    Window* w = new Window();
    w->MakeWindow("My Window", 800, 800);
    glewInit();
    while (w->CheckOpen()) {
        w->PollWindow();
    }
    return 0;
}