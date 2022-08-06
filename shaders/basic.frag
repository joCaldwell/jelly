#version 330 core
in vec3 pos1;
out vec4 FragColor;
void main()
{
    FragColor = vec4(pos1.x, pos1.y, pos1.z, 0.5);
};
