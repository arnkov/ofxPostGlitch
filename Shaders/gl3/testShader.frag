#version 150

uniform sampler2DRect tex0;

in vec2 varyingtexcoord;

out vec4 outputColor;

void main()
{
    // get rgb from tex0
    outputColor = texture(tex0, varyingtexcoord);

}
