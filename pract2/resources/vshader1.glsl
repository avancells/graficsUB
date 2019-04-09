#version 330

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vColor;
layout (location = 2) in vec4 vNormal;
layout (location = 3) in vec2 vCoordTex;

uniform mat4 model_view;
uniform mat4 projection;

out vec2 coordTex;




struct Material{
    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
    float opacity;
    float shine;
};

uniform Material InfoMaterial;


struct AmbientLight{
    vec3 ambientGlobal;
};

uniform AmbientLight InfoAmbient;


struct Light{
    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
    vec3 attenuation;
    vec4 position;
    int tipus;
};

uniform Light light[3];

out vec4 color;

void main()
{
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;
    color = vec4(InfoMaterial.diffuse,1.0);
    //color =  normalize(vec4(InfoMaterial.diffuse,1.0) + vec4(InfoAmbient.ambientGlobal, 1.0));
    coordTex = vCoordTex;

}
