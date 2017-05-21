#version 330 core

in vec3 pos;

out vec4 color;

void main() {
    color = vec4(0.5+pos/2.0, 1.0f);
}
