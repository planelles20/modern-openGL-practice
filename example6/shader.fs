#version 330 core

in vec3 ourColor;

uniform float time;

out vec4 color;

void main()
{
    vec2 p = gl_PointCoord* 2.0 - vec2(1.0);
    float r = sqrt(dot(p,p));

    float theta = atan(p.y,p.x);

    color = vec4(ourColor, 1.0f);

    if(dot(p,p)> 5.0/cos(theta-100*r*sin(time/10.0)) || r > 1.0 || r > 1.0)
        discard;
    else
        color = vec4(ourColor, 1.0f);
}
