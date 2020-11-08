#include <iostream>
#include <string>
#include "Object.h"
#include <vector>
#pragma once
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void AddObject(glm::vec3 position);
	void Update();
	static SceneManager& get();
private:

	std::vector<Object*> scene;
};
static SceneManager sceneManager;