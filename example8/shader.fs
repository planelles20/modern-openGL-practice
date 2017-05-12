#version 330 core

in vec3 ourColor;

uniform float time;

out vec4 color;

void main()
{

    if(dot(gl_PointCoord-0.5,gl_PointCoord-0.5)>0.01)
        discard;
    else
        color = vec4(ourColor, 1.0f);
}
