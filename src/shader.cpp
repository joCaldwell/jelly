#include "internal.hpp"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

std::string parseShader(std::string file_string) {
    std::ifstream file;
    file.open(file_string);
    std::string result;
    result.assign(  (std::istreambuf_iterator<char>(file)),
                    (std::istreambuf_iterator<char>()    ));
    return result;
};

unsigned int compileShader(int type, const char* source) {
    unsigned int result = glCreateShader(type);
    int success;
    char infoLog[512];
    glShaderSource(result, 1, &source, NULL);
    glCompileShader(result);
    glGetShaderiv(result, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(result, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    };
    return result;
};

// Uniforms
void setUniformI(const char* name, int value, unsigned int shaderID){
    int loc = glGetUniformLocation(shaderID, name);
    glUniform1i(loc, value);
};
void setUniformF(const char* name, float value, unsigned int shaderID){
    int loc = glGetUniformLocation(shaderID, name);
    glUniform1f(loc, value);
};
void setUniformB(const char* name, bool value, unsigned int shaderID){
    int loc = glGetUniformLocation(shaderID, name);
    int val = (int)value;
    glUniform1i(loc, val);
};
void setUniform4matF(const char* name, glm::mat4 value, unsigned int shaderID){
    int loc = glGetUniformLocation(shaderID, name);
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
};
void setUniform4vecI(const char* name, glm::vec4 value, unsigned int shaderID){
    int loc = glGetUniformLocation(shaderID, name);
    glUniform4i(loc, value.x, value.y, value.z, value.w);
};
void setUniform4vecF(const char* name, glm::vec4 value, unsigned int shaderID){
    int loc = glGetUniformLocation(shaderID, name);
    glUniform4f(loc, value.x, value.y, value.z, value.w);
};
