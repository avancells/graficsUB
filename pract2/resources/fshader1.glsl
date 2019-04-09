#version 330

in vec4 color;
in vec2 coordTex;
out vec4 colorOut;

uniform sampler2D texture;

void main()
{
    colorOut = color;//*0.25 + 0.75 * texture2D(texture, coordTex);
    //colorOut = color;//vec4(0.0,coordTex.x, coordTex.y,1.0);
}

