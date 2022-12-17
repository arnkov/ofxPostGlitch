#version 150

uniform sampler2DRect tex0;
uniform int imgWidth,imgHeight;
uniform float rand;
uniform int flags;
uniform vec2 blur_vec;
int flgs;
float pix_w,pix_h;
in vec2 pos;

out vec4 outColor;

void main (void)
{
    pix_w = 1.0;
    pix_h = 1.0;
    flgs = flags;
    
    vec2 texCoord = vec2(pos.x, pos.y);

    vec4 col = texture2DRect(tex0,texCoord);


    vec4 col_s[5],col_s2[5];
    for (int i = 0;i < 5;i++){
        col_s[i] = texture2DRect(tex0,texCoord +  vec2(-pix_w*float(i)*blur_vec.x ,-pix_h*float(i)*blur_vec.y));
        col_s2[i] = texture2DRect(tex0,texCoord + vec2( pix_w*float(i)*blur_vec.x , pix_h*float(i)*blur_vec.y));
    }
    col_s[0] = (col_s[0] + col_s[1] + col_s[2] + col_s[3] + col_s[4])/5.0;
    col_s2[0]= (col_s2[0]+ col_s2[1]+ col_s2[2]+ col_s2[3]+ col_s2[4])/5.0;
    col = (col_s[0] + col_s2[0]) / 2.0;
        
    outColor = col.rgba;
}
