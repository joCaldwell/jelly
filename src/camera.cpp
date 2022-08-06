#include "internal.hpp"
#include <iostream>
#include <glm/glm.hpp>

Camera::Camera()
    : pos(glm::vec3(0)), dir(glm::vec3(0)), raxis(glm::vec3(0)), uaxis(glm::vec3(0))
{};
Camera::Camera(glm::vec3 pos, glm::vec3 target)
    : pos(glm::vec3(0)), dir(glm::vec3(0)), raxis(glm::vec3(0)), uaxis(glm::vec3(0))
{
    this->pos = pos;
    this->dir = glm::normalize(pos-target);
    this->raxis = glm::normalize(glm::cross(UP, this->dir));
    this->uaxis = glm::cross(this->dir, this->raxis);
};
