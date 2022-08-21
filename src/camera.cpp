#include <iostream>
#include <glm/glm.hpp>
#include <cmath>
#include "internal.hpp"

Camera::Camera()
    : pos(glm::vec3(0)), target(glm::vec3(0)),fov(0.0f), dir(glm::vec3(0)), raxis(glm::vec3(0)), uaxis(glm::vec3(0)), far(0.0), near(0.0)
{};
Camera::Camera(glm::vec3 pos, glm::vec3 target)
    : pos(pos), target(target), fov(0.0f), dir(glm::vec3(0)), raxis(glm::vec3(0)), uaxis(glm::vec3(0)), far(0.0), near(0.0)
{
    this->target = glm::normalize(target);
    this->pos = pos;
    this->dir = this->pos + target;
    this->raxis = glm::normalize(glm::cross(UP, this->dir));
    this->uaxis = glm::cross(this->dir, this->raxis);
};

void Camera::moveCam(glm::vec3 change) {
    this->pos += change;
    this->dir = this->pos + this->target;
};

void Camera::rotateCam(glm::vec3 rotation) {
    this->target.x = cos(rotation.x + atan(target.z/target.x)) * cos(rotation.y);
    this->target.y = sin(rotation.y);
    this->target.z = sin(rotation.x + atan(target.x/target.z) * cos(rotation.y));
    this->target = glm::normalize(this->target);
    this->dir = this->pos + this->target;
};
