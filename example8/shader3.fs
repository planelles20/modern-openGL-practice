#version 330 core

in vec3 ourColor;
in float frec;

uniform float time;

out vec4 color;

void main()
{

    if(dot(gl_PointCoord-0.5,gl_PointCoord-0.5)>0.01)
        discard;
    else
        color = 0.4*vec4(sin(frec*time)+0.6, 0.4*sin(2.0*frec*time)+0.6, 0.4*sin(3.0*frec*time)+0.6, 1.0f);
}
