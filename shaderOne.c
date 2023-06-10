vec3 palette(float t) {

    vec3 a = vec3(0.300, 0.500, 0.500);
    
    vec3 b = vec3(-2.452, 2.008, 0.500); 
    
    vec3 c = vec3(1.000, 1.000, 1.000); 
    
    vec3 d = vec3(0.000, 0.333, 0.667);

    return a + b*cos(6.28318*(c*t+d));
}

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = (fragCoord * 2.0 - iResolution.xy) / iResolution.y;
    
    vec2 uv0 = uv;
    
    vec3 finalColor = vec3(0.0);
    
    for(float i = 0.0; i < 3.0; i++) {
   
        uv = fract(uv * 2.5) - 0.5;

        float d = length(uv) * exp(-length(uv0));

        vec3 col = palette(length(uv0) + i*.4 + iTime*0.4);

        d = sin(d*15. + iTime)/15.;

        d = abs(d);

        d = pow(0.02 / d, 1.2);

        finalColor += col * d;
    }
    
    fragColor= vec4(finalColor, 1.0);
}