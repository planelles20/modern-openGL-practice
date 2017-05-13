#version 330 core
layout (location = 0) in vec3 position;

uniform float time;

void main()
{
	float x = position.x;
	float y = position.y;
	float z = position.z;
	float w = 1.0f;
    gl_Position = vec4(x, y, z, w);
}
