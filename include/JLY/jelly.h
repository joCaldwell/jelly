#pragma once
#include <glm/glm.hpp>
#include <string>
#include <vector>

#define UP glm::vec3(0.0f, 1.0f, 0.0f)

// Initial refernces
struct Object;
struct Scene;
struct Camera;

void RenderScene(Scene, Camera);

struct Object {
    Object();
    Object(std::string &file);
    unsigned int num_verticies;
    unsigned int num_triangles;
    std::vector<glm::vec3> verticies;
    std::vector<glm::vec3> triangles;
    glm::vec3 center;
    glm::vec3 rotation;
    glm::vec3 translation;
    glm::vec3 scaling;
};

struct Scene {
    Scene();
    void addObject(Object obj);
    std::vector<Object> objects;
};

struct Camera {
    Camera();
    Camera(glm::vec3 pos, glm::vec3 target);
    glm::vec3 pos;
    glm::vec3 dir;
    glm::vec3 raxis;
    glm::vec3 uaxis;

};


void use_shader(std::string file);
