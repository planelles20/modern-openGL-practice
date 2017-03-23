#version 330 core
layout (location = 0) in vec3 position;

out vec3 ourPos;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0f);
    ourPos = position;
}
