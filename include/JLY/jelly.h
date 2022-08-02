#pragma once
#include <glm/glm.hpp>
#include <string>
#include <vector>

// Initial refernces
struct Object;
struct Scene;

void RenderScene(Scene);

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


void use_shader(std::string file);
