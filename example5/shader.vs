#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform float time;

out vec3 ourColor;

void main()
{
    float x = position.x; //*cos(time);
    float y = position.y; //*sin(time);

    gl_Position = vec4(x, y, position.z, 1.0f);
    ourColor = color;
}
