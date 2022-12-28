#pragma once
#include "internal.hpp"

struct Camera {
    Camera();
    Camera(glm::vec3 pos, glm::vec3 target);
    void moveCam(glm::vec3);
    void rotateCam(glm::vec3);
    float fov;
    float near;
    float far;
    glm::vec3 target;
    glm::vec3 rotation;
    glm::vec3 pos;
    glm::vec3 dir;
    glm::vec3 raxis;
    glm::vec3 uaxis;
};
