#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "internal.hpp"

void processInput(GLFWwindow *window) {
    //cam->movement
    if (glfwGetKey(window, GLFW_KEY_W)) {
        main_cam->moveCam(glm::vec3(0,0,F_MOVEMENT_SPD));
    };
    if (glfwGetKey(window, GLFW_KEY_S)) {
        main_cam->moveCam(glm::vec3(0,0,-B_MOVEMENT_SPD));
    };
    if (glfwGetKey(window, GLFW_KEY_A)) {
        main_cam->moveCam(glm::vec3(L_MOVEMENT_SPD,0,0));
    };
    if (glfwGetKey(window, GLFW_KEY_D)) {
        main_cam->moveCam(glm::vec3(-R_MOVEMENT_SPD,0,0));
    };
    if (glfwGetKey(window, GLFW_KEY_Q)) {
        main_cam->moveCam(glm::vec3(0,U_MOVEMENT_SPD,0));
    };
    if (glfwGetKey(window, GLFW_KEY_E)) {
        main_cam->moveCam(glm::vec3(0,-D_MOVEMENT_SPD,0));
    };
    if (glfwGetKey(window, GLFW_KEY_UP)) {
        main_cam->rotateCam(glm::vec3(PITCH_SPEED,0,0));
    };
    if (glfwGetKey(window, GLFW_KEY_DOWN)) {
        main_cam->rotateCam(glm::vec3(-PITCH_SPEED,0,0));
    };
    if (glfwGetKey(window, GLFW_KEY_LEFT)) {
        main_cam->rotateCam(glm::vec3(0,-YAW_SPEEED,0));
    };
    if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
        main_cam->rotateCam(glm::vec3(0,YAW_SPEEED,0));
    };
};


