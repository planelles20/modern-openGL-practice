#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform float time;

out vec3 ourPos;
out vec3 ourColor;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0f);
    ourPos = position;
    ourColor = color;
}
