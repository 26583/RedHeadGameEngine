#include "Window.h"
#include <string>
#include <iostream>

Window::Window()
{
}

Window::~Window()
{
}

void Window::MakeWindow(std::string windowName, int sizeX, int sizeY)
{
    sf::ContextSettings settings;
    settings.majorVersion = 3;
    settings.minorVersion = 1;
	window.create(sf::VideoMode(sizeX, sizeY), windowName, sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    // activate the window
    window.setActive(true);
    running = true;
    
}

void Window::CloseWindow()
{
	window.close();
}

bool Window::CheckOpen()
{
	return running;
}

void Window::PollWindow()
{

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            // end the program
            running = false;
        }
        else if (event.type == sf::Event::Resized)
        {
            // adjust the viewport when the window is resized
            glViewport(0, 0, event.size.width, event.size.height);
        }
    }

    // clear the buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // draw...
    Canvas canvas = Canvas();
    canvas.Draw(&window);
    // end the current frame (internally swaps the front and back buffers)
    window.display();
}