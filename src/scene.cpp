#include "internal.hpp"

Scene::Scene()
    : objects(std::vector<Object>())
{};

void Scene::addObject(Object obj){
    this->objects.push_back(obj);
};
