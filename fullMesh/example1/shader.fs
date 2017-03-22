#version 330 core
in vec3 ourPos;
in vec3 ourColor;

uniform float time;

out vec4 color;

void main()
{
    float r = 1.0*pow(pow(ourPos.x-0.5*sin(time),2)+pow(ourPos.y-0.5*cos(time),2),0.5);
    float g = 0.5*pow(pow(ourPos.x-0.5*sin(time),2)+pow(ourPos.y-0.5*cos(time),2),0.5);
    float b = 1.0-pow(pow(ourPos.x-0.5*cos(time),2)+pow(ourPos.y-0.5*sin(time),2),0.5);
    float a = 1.0f;
    color = vec4(r, g, b, a);
}
