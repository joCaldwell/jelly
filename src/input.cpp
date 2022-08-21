#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "internal.hpp"

void processInput(GLFWwindow *window, Scene scene) {
    //cam movement
    if (glfwGetKey(window, GLFW_KEY_W)) {
        scene.cam.moveCam(glm::vec3(0,0,F_MOVEMENT_SPD));
    };
    if (glfwGetKey(window, GLFW_KEY_S)) {
        scene.cam.moveCam(glm::vec3(0,0,-B_MOVEMENT_SPD));
    };
    if (glfwGetKey(window, GLFW_KEY_A)) {
        scene.cam.moveCam(glm::vec3(L_MOVEMENT_SPD,0,0));
    };
    if (glfwGetKey(window, GLFW_KEY_D)) {
        scene.cam.moveCam(glm::vec3(-R_MOVEMENT_SPD,0,0));
    };
    if (glfwGetKey(window, GLFW_KEY_Q)) {
        scene.cam.moveCam(glm::vec3(0,U_MOVEMENT_SPD,0));
    };
    if (glfwGetKey(window, GLFW_KEY_E)) {
        scene.cam.moveCam(glm::vec3(0,-D_MOVEMENT_SPD,0));
    };
    if (glfwGetKey(window, GLFW_KEY_UP)) {
        scene.cam.rotateCam(glm::vec3(0.001,0,0));
    };
};


