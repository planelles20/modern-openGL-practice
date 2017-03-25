#version 330 core
layout (location = 0) in vec3 position;

uniform float time;

void main()
{	
	float x = position.x*sin(time);
	float y = position.y*sin(time);
	float z = position.z;
	float w = 1.0f;
    gl_Position = vec4(x, y, z, w);
}
