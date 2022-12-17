#version 150

uniform sampler2DRect tex0;
uniform float rand;
uniform int flags;
uniform vec2 blur_vec;
uniform float val1,val2,val3,val4;
uniform float timer;
uniform vec2 u_resolution;

int flgs;
float pix_w,pix_h;

in vec2 pos;

out vec4 outColor;

void main (){

    pix_w = 1.0 / float(pos.x);
    pix_h = 1.0 / float(pos.y);
	
    vec2 texCoord = vec2(max(3.0,min(float(pos.x),pos.x+sin(pos.y/(153.25*rand*rand)*rand+rand*val2+timer*3.0)*val3)),
						  max(3.0,min(float(pos.y),pos.y+cos(pos.x/(251.57*rand*rand)*rand+rand*val2+timer*2.4)*val3)-3.));


    vec4 col = texture2DRect(tex0,texCoord);

    outColor = col.rgba;
}
