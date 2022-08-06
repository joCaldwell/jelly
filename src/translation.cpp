#include "internal.hpp"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

glm::mat4 getRotationMatrix(glm::vec3 rotation){
    glm::mat4 result;
    glm::quat myQuat = glm::quat(rotation);
    result = glm::mat4(myQuat);
    return result;
};
glm::mat4 getTranslationMatrix(glm::vec3 translation){
    glm::mat4 result(0);
    result[3].x = translation.x;
    result[3].y = translation.y;
    result[3].z = translation.z;
    result[0].x = 1;
    result[1].y = 1;
    result[2].z = 1;
    result[3].w = 1;
    return result;
};
glm::mat4 getScaleMatrix(glm::vec3 scale){
    glm::mat4 result(0);
    result[0].x = scale.x;
    result[1].y = scale.y;
    result[2].z = scale.z;
    result[3].w = 1;
    return result;
};

glm::mat4 getViewMatrix(Camera cam) {
    glm::mat4 result;
    result = glm::lookAt(cam.pos, cam.dir, UP);
    return result;
};

glm::mat4 getProjectionMatrix(float fov, float aspect, float near, float far) {
    glm::mat4 result;
    result = glm::perspective(fov, aspect, near, far);
    return result;
};
