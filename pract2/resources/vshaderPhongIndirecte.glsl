#version 330
layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vColor;
layout (location = 2) in vec4 vNormal;
layout (location = 3) in vec2 vCoordTex;

uniform mat4 model_view;
uniform mat4 projection;

uniform vec4 center;

out vec4 positionOut;
out vec4 colorOut;
out vec4 normalOut;
out vec2 coordTex;

void main()
{
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;
    positionOut = vPosition;
    colorOut = vColor;
    normalOut = vNormal;

    //calcul vertex textura indirecte
    vec4 pos = normalize(vPosition - center);
    float u = 0.5 - atan(pos.z, pos.x)/(2.0*3.14159265);
    float v = 0.5 - asin(pos.y)/3.14159265;
    coordTex = vec2(u,v);
}

