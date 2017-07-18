#version 330 core

in vec3 pos_fs;

uniform float time;

out vec4 color;

void main()
{
    //vec2 p = gl_PointCoord*2.0 - vec2(1.0);

    //polar coordenates
    float r = pow(pos_fs.x*pos_fs.x+pos_fs.y*pos_fs.y,0.5);
    float alpha = atan(pos_fs.y/pos_fs.x);

    //faclulate functions
    int N = int(time/10.0)+1;
    float f = sin(2.0*N*alpha+2.0*time);

    if(r<f)
        color = vec4(f, 0.0f, 1.0f, 1.0f);
    else
        color = vec4(0.0, 0.0, 0.0f, 1.0f);
}
