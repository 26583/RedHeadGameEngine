#include "SceneManager.h"
#include <string>
#include <iostream>
#include <assert.h>

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::AddObject(float _x, float _y, float _z)
{
    Object* object = new Object();
    object->SetPosition(_x, _y, _z);
    scene.push_back(object);
}

void SceneManager::Update()
{
    glClearColor(0.78, 0.94, 0.94, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (int i =0; i < scene.size(); i++) {
        scene[i]->Draw();
    }
}

SceneManager& SceneManager::get()
{
    static SceneManager* gpSingleton = NULL;
    if (gpSingleton == NULL)
    {
        gpSingleton = new SceneManager();
    }
    assert(gpSingleton);
    return *gpSingleton;
}
