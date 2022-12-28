#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
//#include <assimp/Importer.hpp>
#include "internal.hpp"

Object::Object()
    : num_verticies(0), num_triangles(0), verticies(std::vector<glm::vec3>(0)), indexes(),
    rotation(glm::vec3(0)), translation(glm::vec3(0)), scaling(glm::vec3(1)), center(glm::vec3(0)), has_normals(false)
{};

Object::Object(std::string &file)
    : num_verticies(0), num_triangles(0), verticies(std::vector<glm::vec3>(0)), indexes(),
    rotation(glm::vec3(0)), translation(glm::vec3(0)), scaling(glm::vec3(1)), center(glm::vec3(0)), has_normals(false)
{
    std::ifstream myfile; //use all the method of the ifstream
    myfile.open(file);
    if(!myfile.is_open()) {
        std::cout << "could not open object file " << file << std::endl;
        return;
    }
    std::string line;
    while(std::getline(myfile, line)){
        //g group name
        if (line.find("g ") != std::string::npos) {
        };
        //s smooting group
        //o object name
        //bevel interpolation (bevel)
        //color interpolation (c_interp)
        //dissolve interpolation (d_interp)
        //level of detail (lod)
        //material name (usemtl)
        //material library (mtllib)
        //shadow casting (shadow_obj)
        //ray tracing (trace_obj)
        //curve approximation technique (ctech)
        //surface approximation technique (stech)
        
        //v geometric verticies
        if (line.find('v') != std::string::npos) {
            this->num_verticies++;
            std::istringstream v(line.substr(2));
            double x,y,z;
            v>>x;v>>y;v>>z;
            glm::vec3 vert(x,y,z);
            this->verticies.push_back(vert);
            this->center += vert;
        //vt texture verticies
        //vn vertex normals
        //vp parameter space verticies
        //f face
        } else if (line.find("f ") != std::string::npos) {
            this->num_triangles++;
            bool has_normals = false;
            bool has_texture = false;
            if (line.find('/') != std::string::npos){ 
                this->has_normals = true;
            };
            std::vector<std::string> elems = SplitString(line, ' ');
            ObjIndex *verts = ParseIndexWithNormal(elems);
            for (int i=0; i<elems.size()-3; i++){
                this->indexes.push_back(verts[i]);
            }
        }
        //p point
        //l line
        //curv curve
        //curv2 2d curve
        //surf surface
    };
    this->center/=this->num_verticies;
    myfile.close();
};

void Object::moveCenter(glm::vec3 centerchange) {
    this->translation += centerchange;
    center += centerchange;
};

ObjIndex* Object::ParseIndexWithNormal(std::vector<std::string> elems) {
    ObjIndex* result = (ObjIndex*)malloc(sizeof(ObjIndex)*(elems.size()-3));
    // v/vt/vn
    for(int i=1; i<elems.size()-2; i++) {
        std::vector<std::string> x = SplitString(elems[1], '/');
        std::vector<std::string> y = SplitString(elems[i+1], '/');
        std::vector<std::string> z = SplitString(elems[i+2], '/');
        if (x.size() == 3) {
            result[i-1].verticies = glm::vec3(std::stoi(x[0])-1,std::stoi(y[0])-1,std::stoi(z[0])-1);
            result[i-1].texcoords = glm::vec3(std::stoi(x[1])-1,std::stoi(y[1])-1,std::stoi(z[1])-1);
            result[i-1].normals = glm::vec3(std::stoi(x[2])-1,std::stoi(y[2])-1,std::stoi(z[2])-1);
        } else if (x.size() == 2) {
            result[i-1].verticies = glm::vec3(std::stoi(x[0])-1,std::stoi(y[0])-1,std::stoi(z[0])-1);
            result[i-1].texcoords = glm::vec3(std::stoi(x[1])-1,std::stoi(y[1])-1,std::stoi(z[1])-1);
            result[i-1].normals = glm::vec3(0);
        } else {
            result[i-1].verticies = glm::vec3(std::stoi(x[0])-1, std::stoi(y[0])-1, std::stoi(z[0])-1);
            result[i-1].texcoords = glm::vec3(0);
            result[i-1].normals = glm::vec3(0);
        };
    }
    return result;
};

std::vector<std::string> SplitString(const std::string &s, char delim) {
    std::vector<std::string> elems;
        
    const char* cstr = s.c_str();
    unsigned int strLength = s.length();
    unsigned int start = 0;
    unsigned int end = 0;
        
    while(end <= strLength)
    {
        while(end <= strLength)
        {
            if(cstr[end] == delim)
                break;
            end++;
        }
        if (end > start) {
            elems.push_back(s.substr(start, end - start));
        } else {
            elems.push_back("0");
        }
        start = end + 1;
        end = start;
    }
    return elems;
}


