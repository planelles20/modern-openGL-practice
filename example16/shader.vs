#version 330 core
layout (location = 0) in vec3 position;

uniform float time;

out vec3 pos_fs;

void main()
{
    gl_Position = vec4(position, 1.0f);
	pos_fs = position;

}
