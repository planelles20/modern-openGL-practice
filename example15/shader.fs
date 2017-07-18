#version 330 core

in vec3 ourColor;

uniform float time;

out vec4 color;

void main()
{
    vec2 p = gl_PointCoord* 2.0 - vec2(1.0);
    float r = sqrt(dot(p,p));

    int N = int(time/15)+2;

    float theta = float(N)*atan(p.y,p.x)+time*10.0;

    if((dot(p,p)>5.0/cos(theta-100.0*r))  || (r > 1.5))
        discard;
    else
        color = vec4(vec3(0.5+0.5*sin(r/2.0+sin(time*0.5)/2.0),
                          0.5+0.5*cos(r/2.0+sin(time*1.0)/2.0),
                          0.5+0.5*sin(r/2.0+sin(time*1.5)/2.0)),
                          1.0f);

}
