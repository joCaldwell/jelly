#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

struct Camera;
glm::mat4 getRotationMatrix(glm::vec3 rotation);
glm::mat4 getTranslationMatrix(glm::vec3 translation);
glm::mat4 getScaleMatrix(glm::vec3 scale);
glm::mat4 getViewMatrix(Camera cam);
glm::mat4 getProjectionMatrix(float fov, float aspect, float near, float far);
