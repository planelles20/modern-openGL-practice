#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform float time;

out vec3 ourColor;

void main()
{
    float n = 5;
    float x = position.x+cos(time)/n+sin(time/2.0)/n+cos(time/3.0)/n;//+sin(time/4.0)/n+cos(time/5.0)/n;
    float y = position.y+sin(time)/n+cos(time/2.0)/n+sin(time/3.0)/n;//+cos(time/4.0)/n+sin(time/5.0)/n;

    gl_Position = vec4(x, y, position.z, 1.0f);
    ourColor = color;
}
