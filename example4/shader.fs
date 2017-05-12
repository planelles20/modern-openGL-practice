#version 330 core

in vec3 ourColor;

uniform float time;

out vec4 color;

void main()
{
    float x = (gl_FragCoord.x - 1200.0f / 2.0f) / (1200.0f / 2.0f);
    float y = (gl_FragCoord.y - 800.0f / 2.0f) / (800.0f / 2.0f);


    if(dot(gl_PointCoord-0.5,gl_PointCoord-0.5)>0.25)
        discard;
    else
        color = vec4(ourColor, 1.0f);
}
