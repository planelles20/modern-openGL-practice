#version 330 core

uniform float time;

out vec4 color;

vec2 prod(vec2 v1, vec2 v2){
    vec2 aux;
    aux.x = v1.x*v2.x - v1.y*v2.y;
    aux.y = v1.x*v2.y + v1.y*v2.x;
    return aux;
}

void main()
{
    //pixel coordenates [-2, 2]
    vec2 pixel = vec2(4.0*gl_FragCoord.x/1200-2.0, 4.0*gl_FragCoord.y/800-2.0);

    vec2 z = vec2(pixel.x, pixel.y);

    //constant value for fractal
    float aureo = 1.61803398874989484820458683436563811772;
    vec2 c = vec2(0.0,0.0);

    // fractal type
    int j;
    int ite = 30;

    if(time<=ite){
        j = int(time)%ite;
        c = vec2(1-aureo,0.0);
    }
    else if(time<=2*ite){
        j = int(time)%ite;
        c = vec2(-0.835,-0.2321);
    }
    else if(time<=3*ite){
        j = int(time)%ite;
        c = vec2(aureo-2.0,aureo-1.0);
    }
    else if(time<=4*ite){
        j = int(time)%ite;
        c = vec2(-1.3,0.00525);
    }
    else if(time<=5*ite){
        j = int(time)%ite;
        c = vec2(-0.72,-0.196);
    }
    else if(time<=6*ite){
        j = int(time)%ite;
        c = vec2(-0.1,0.87);
    }
    else if(time<=7*ite){
        j = int(time)%ite;
        c = vec2( -0.51,-0.601);
    }
    else {
        j = int(time)%ite;
        c = vec2( pixel.x,pixel.y);
    }

    //calculate
    for(int i=0; i<=j; i++){
        z = prod(z,z) + c;
        if(pow(z.x*z.x+z.y*z.y,0.5) > 2.0)
            break;
    }

    if(pow(z.x*z.x+z.y*z.y,0.5) > 2.0){
        discard;
    }
    else {
        color = vec4(abs(z.x)/pow(z.x*z.x+z.y*z.y,0.5), abs(z.y)/pow(z.x*z.x+z.y*z.y,0.5), 0.0f, 1.0f);
    }
}
