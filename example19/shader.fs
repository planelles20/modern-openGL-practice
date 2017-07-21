#version 330 core

in vec3 pos;

uniform float time;

out vec4 color;

void main()
{
    if(sin(time*pos.x*pos.y*pos.z)<0)
        discard;

    color = vec4(0.5*pos.x+0.5, 0.5*pos.y+0.5, 0.5*pos.z+0.5, 1.0);
}
