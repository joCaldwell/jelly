#include "internal.hpp"

Scene::Scene(Camera &cam)
    : objects(std::vector<Object>()), cam(cam)
{};

void Scene::addObject(Object obj){
    this->objects.push_back(obj);
};
void Scene::addCamera(Camera &cam){
    this->cam = cam;
};
