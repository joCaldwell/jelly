#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

#define PI 3.141592
#define RIGHT glm::vec3(1.0f, 0.0f, 0.0f)
#define UP glm::vec3(0.0f, 1.0f, 0.0f)
#define FORWARD glm::vec3(0.0f, 0.0f, 1.0f)

#ifndef F_MOVEMENT_SPD
#define F_MOVEMENT_SPD 0.025f
#endif
#define B_MOVEMENT_SPD 0.025f
#define R_MOVEMENT_SPD 0.025f
#define L_MOVEMENT_SPD 0.025f
#define U_MOVEMENT_SPD 0.025f
#define D_MOVEMENT_SPD 0.025f

#define ROTATE_SPEED 0.025f
#define PITCH_SPEED 0.025f
#define YAW_SPEEED 0.025f
#define ROLL_SPEED 0.025f

// Initial refernces


struct Object;
struct Scene;
struct Camera;


void RenderScene(Scene);

struct Object {
    Object();
    Object(std::string &file);
    void moveCenter(glm::vec3);

    unsigned int num_verticies;
    unsigned int num_triangles;
    std::vector<glm::vec3> verticies;
    std::vector<glm::vec3> triangles;
    glm::vec3 center;
    glm::vec3 rotation;
    glm::vec3 translation;
    glm::vec3 scaling;
};

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

extern Camera *main_cam;

struct Scene {
    Scene(Camera &cam);
    void addObject(Object obj);
    void addCamera(Camera &cam);
    std::vector<Object> objects;
    Camera &cam;
};

void use_shader(std::string file);
void processInput(GLFWwindow *window, Scene scene);
