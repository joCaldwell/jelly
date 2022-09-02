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
    this->raxis = glm::normalize(glm::cross(UP, this->target));
    this->uaxis = glm::cross(this->target, this->raxis);
    this->rotation.x = atan(this->target.y / this->target.z);
    this->rotation.y = atan(this->target.z / this->target.x);
    this->rotation.z = atan(this->target.y / this->target.x);
};

void Camera::moveCam(glm::vec3 change) {
    this->raxis = glm::normalize(glm::cross(UP, this->target));
    this->uaxis = glm::normalize(glm::cross(this->target, this->raxis));
    glm::vec3 new_target = glm::normalize(glm::vec3(this->target.x,0,this->target.z));
    glm::mat3 matrix = glm::mat3(this->raxis,UP,new_target);
    glm::vec3 new_change = matrix*change;
    this->pos += new_change;
    this->dir = this->pos + this->target;
    std::cout <<  "u " << uaxis.x << ", "
        << new_change.x << ", "
        << pos.x
        << std::endl;
    std::cout <<  "r " << raxis.x << ", "
        << raxis.y << ", "
        << raxis.z
        << std::endl;
    std::cout <<  "target " << target.x << ", "
        << target.y << ", "
        << target.z
        << std::endl;
};

void Camera::rotateCam(glm::vec3 Drotation) {
    this->raxis = glm::normalize(glm::cross(UP, this->target));
    this->uaxis = glm::normalize(glm::cross(this->target, this->raxis));
    this->rotation.x = (((this->rotation.x + Drotation.x) <= PI/2-0.05) && ((this->rotation.x + Drotation.x) >= -PI/2+0.05))
        ? this->rotation.x + Drotation.x 
        : this->rotation.x;
    this->rotation.y = (this->rotation.y + Drotation.y) <= 2*PI ? this->rotation.y + Drotation.y :this->rotation.y + Drotation.y - 2*PI;
    this->rotation.z = (this->rotation.z + Drotation.z) <= 2*PI ? this->rotation.z + Drotation.z :this->rotation.z + Drotation.z - 2*PI;
    this->target.x = cos(Drotation.y + rotation.y) * cos(Drotation.x + rotation.x);
    this->target.y = sin(Drotation.x + rotation.x);
    this->target.z = sin(Drotation.y + rotation.y) * cos(Drotation.x + rotation.x);
    this->target = glm::normalize(this->target);
    this->dir = this->pos + this->target;
};
