#version 330 core

in vec3 ourColor;

uniform float time;

out vec4 color;

void main()
{
    float r = ourColor.x;
    float g = ourColor.y;
    float b = ourColor.z;
    float a = 1.0f;
    color = vec4(ourColor, a);
}
