#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "../../src/internal.hpp"

#define PI 3.141592
#define RIGHT glm::vec3(1.0f, 0.0f, 0.0f)
#define UP glm::vec3(0.0f, 1.0f, 0.0f)
#define FORWARD glm::vec3(0.0f, 0.0f, 1.0f)

#ifndef F_MOVEMENT_SPD
#define F_MOVEMENT_SPD 0.095f
#endif
#define B_MOVEMENT_SPD 0.065f
#define R_MOVEMENT_SPD 0.065f
#define L_MOVEMENT_SPD 0.065f
#define U_MOVEMENT_SPD 0.065f
#define D_MOVEMENT_SPD 0.065f

#define ROTATE_SPEED 0.065f
#define PITCH_SPEED 0.065f
#define YAW_SPEEED 0.065f
#define ROLL_SPEED 0.065f

// Initial refernces
struct Object;
struct Scene;
struct Camera;

//global variable declaration
//extern Camera *main_cam;

void RenderScene(Scene);
void use_shader(std::string file);
