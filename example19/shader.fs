#version 330 core

in vec3 pos;

uniform float time;

out vec4 color;

void main()
{
    float frec = mod(time, 60.0);

    if (sin(frec*pos.x*pos.y*pos.z)<0 && time < 60.0)
        discard;
    else if (cos(frec*pos.x*pos.y*pos.z)<0 && time < 2*60.0)
        discard;
    else if (tan(frec*pos.x*pos.y*pos.z)<0 && time < 3*60.0)
        discard;
    else if (cos(frec*pos.x*pos.y*pos.z)*sin(frec*pos.x*pos.y*pos.z)<0 && time < 4*60.0)
        discard;

    color = vec4(0.5*pos.x+0.5, 0.5*pos.y+0.5, 0.5*pos.z+0.5, 1.0);
}
