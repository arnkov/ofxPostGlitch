#version 150

uniform sampler2DRect tex0;
uniform int imgWidth,imgHeight;
uniform float rand;
uniform int flags;
uniform vec2 blur_vec;
uniform float val1,val2,val3,val4;
int flgs;
float pix_w,pix_h;
in vec2 pos;
out vec4 outColor;

void main (void)
{
    vec2 texCoord = vec2(pos.x , pos.y);
	vec4 col = texture2DRect(tex0,texCoord);;
	col.r = 1.0 - col.r;
	col.g = 1.0 - col.g;
	col.b = 1.0 - col.b;
	outColor = col;
}
