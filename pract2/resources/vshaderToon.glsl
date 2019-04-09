#version 330
layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vColor;
layout (location = 2) in vec4 vNormal;

uniform mat4 model_view;
uniform mat4 projection;

out vec4 positionOut;
out vec4 colorOut;
out vec4 normalOut;

void main()
{
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;
    positionOut = vPosition;
    colorOut = vColor;
    normalOut = vNormal;
}


