#pragma once
#include <string>
#include <glm/glm.hpp>

std::string parseShader(std::string file);

unsigned int compileShader(int type, const char* source);

// unifroms
void setUniformI(const char*, int, unsigned int);
void setUniformF(const char*, float, unsigned int);
void setUniformB(const char*, int, unsigned int);
void setUniform4matF(const char*, glm::mat4, unsigned int);
void setUniform4vecI(const char*, glm::vec4, unsigned int);
void setUniform4vecF(const char*, glm::vec4, unsigned int);
