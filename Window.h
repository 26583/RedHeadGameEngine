#include <GL/glew.h>
#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include "Canvas.h"
#include <SFML/OpenGL.hpp>

#pragma once
class Window
{
public:
	Window();
	~Window();
	void MakeWindow(std::string windowName, int sizeX, int sizeY);
	void CloseWindow();
	bool CheckOpen();
	void PollWindow();
	static Window& get();
private:
	sf::Window window;
	bool running;
	//Canvas canvas;
};
static Window windowManager;

