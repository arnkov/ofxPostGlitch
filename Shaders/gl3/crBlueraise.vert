#version 150

uniform mat4 modelViewProjectionMatrix;

in vec4 position;

out vec2 pos;

void main(void)
{
	pos = position.xy;
    gl_Position = modelViewProjectionMatrix * position;
}
