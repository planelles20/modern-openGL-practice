#version 330 core

in vec3 pos;

uniform float time;

out vec4 color;

void main()
{
    float x = 0.5*pos.x+0.5;
    float y = 0.5*pos.y+0.5;
    float z = 0.5*pos.z+0.5;

    color = vec4(x, y, z, 1.0);
}
