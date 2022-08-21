#version 330 core
layout (location = 0) in vec3 aPos;
uniform mat4 rotation;
uniform mat4 translation;
uniform mat4 scaling;
uniform mat4 view;
uniform mat4 perspective;
out vec3 pos1;

void main()
{
    vec4 pos;
    pos1 = aPos;
    mat4 model = translation * rotation * scaling;
    pos = perspective * view * model * vec4(aPos,1);
    //pos = perspective * model * vec4(aPos,1);
    gl_Position = pos;
};
