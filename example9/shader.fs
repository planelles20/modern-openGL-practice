#version 330 core

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
    vec2 pixel = vec2(4.0*gl_FragCoord.x/1200-2.0, 4.0*gl_FragCoord.y/1000-2.0);

    vec2 z = vec2(pixel.x, pixel.y);

    //constant value for fractal
    float aureo = 1.61803398874989484820458683436563811772;
    vec2 c = vec2(1-aureo,0.0);

    //calculate
    for(int i=0; i<20; i++){
        z = prod(z,z) + c;
        if(pow(z.x*z.x+z.y*z.y,0.5) > 2.0)
            break;
    }

    if(pow(z.x*z.x+z.y*z.y,0.5) > 2.0){
        discard;
    }
    else {
        color = vec4(z.x/0.0000001, z.y/0.0001, 0.5f, 1.0f);
    }
}
