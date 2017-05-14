#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform float time;

out vec3 ourColor;
out float frec;

void main()
{
    float theta = 0.5;

    float n = 0;
    float xaux = 0;
    float yaux = 0;

    float A;
    int i;

    for(i=1; i<=5; i++){
        A = log(float(i));
        n += A+A;
        xaux += A*sin(theta*i*time)+A*cos(theta/i*time);
        yaux += A*cos(theta*i*time)+A*sin(theta/i*time);
    }


    float x = position.x+xaux/n;
    float y = position.y+yaux/n;

    gl_Position = vec4(x, y, position.z, 1.0f);
    ourColor = color;
    frec = theta;
}
