#pragma once
#include "internal.hpp"

struct Scene {
    Scene(Camera &cam);
    void addObject(Object &obj);
    void addCamera(Camera &cam);
    std::vector<Object> objects;
    Camera &cam;
};
