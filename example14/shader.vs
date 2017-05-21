#version 330 core
layout (location = 0) in vec3 position;

out vec3 pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float time;

void main() {

    pos.x = position.x;
    pos.y = position.y;
    pos.z = cos(pos.x+time)+sin(pos.y+time);

    gl_Position = projection * view * model * vec4(pos, 1.0f);
}
