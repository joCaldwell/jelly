#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "internal.hpp"

struct ObjIndex {
    glm::vec3 verticies;
    glm::vec3 texcoords;
    glm::vec3 normals; 
};

struct Object {
    Object();
    Object(std::string &file);
    void moveCenter(glm::vec3);
    ObjIndex *ParseIndexWithNormal(std::vector<std::string> verts);

    bool has_normals;
    unsigned int num_verticies;
    unsigned int num_triangles;
    std::vector<glm::vec3> verticies;
    std::vector<ObjIndex> indexes;
    //std::vector<glm::vec3> triangles;
    glm::vec3 center;
    glm::vec3 rotation;
    glm::vec3 translation;
    glm::vec3 scaling;
};

unsigned int FindNextChar(unsigned int start, const char* str, unsigned int length, char token);
std::vector<std::string> SplitString(const std::string &s, char delim);
