#include "internal.hpp"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

Object::Object()
    : num_verticies(0), num_triangles(0), verticies(std::vector<glm::vec3>(0)), triangles(std::vector<glm::vec3>(0)),
    rotation(glm::vec3(0)), translation(glm::vec3(0)), scaling(glm::vec3(1)), center(glm::vec3(0))
{};

Object::Object(std::string &file)
    : num_verticies(0), num_triangles(0), verticies(std::vector<glm::vec3>(0)), triangles(std::vector<glm::vec3>(0)),
    rotation(glm::vec3(0)), translation(glm::vec3(0)), scaling(glm::vec3(1)), center(glm::vec3(0))
{
    std::ifstream myfile; //use all the method of the ifstream
    myfile.open(file);
    if(!myfile.is_open()) {
        std::cout << "could not open object file " << file << std::endl;
        return;
    }
    std::string line;
    while(std::getline(myfile, line)){
        if (line.find('v') != std::string::npos) {
            this->num_verticies++;
            std::istringstream v(line.substr(2));
            double x,y,z;
            v>>x;v>>y;v>>z;
            glm::vec3 vert(x,y,z);
            this->verticies.push_back(vert);
            this->center += vert;
        } else if (line.find('f') != std::string::npos) {
            this->num_triangles++;
            std::istringstream f(line.substr(2));
            int a,b,c;
            const char* linec = line.c_str();
            sscanf(linec, "f %i %i %i", &a, &b, &c);
            this->triangles.push_back(glm::vec3(a-1,b-1,c-1));
        };
    };
    this->center/=this->num_verticies;
    myfile.close();
};
