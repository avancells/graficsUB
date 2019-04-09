#version 330
in vec4 normalOut;
in vec4 positionOut;

uniform mat4 model_view;
uniform mat4 projection;




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
    float angle;
    vec3 coneDirection;
};

struct NumLights{
    int numL;
};

uniform NumLights numLights;

uniform Light light[10];

uniform vec4 obs;

out vec4 color;

void main()
{

    vec3 tempV = vec3(positionOut.x, positionOut.y, positionOut.z);
    vec3 tempObs = vec3(obs.x, obs.y, obs.z);
    vec3 tempN = vec3(normalOut.x, normalOut.y, normalOut.z);


    vec3 v = normalize(tempObs - tempV);

    vec3 ka = InfoMaterial.ambient; // guardem els valors ambient, specular i diffuse del material
    vec3 ks = InfoMaterial.specular;
    vec3 kd = InfoMaterial.diffuse;

    vec3 c = InfoAmbient.ambientGlobal*ka; // C serà el resultat final d'iluminació, de moment li assignem la llum d'ambient de l'escena


    for(int i = 0; i < numLights.numL; i++){ // per a cada llum de la escena

        vec3 lightPos = vec3(light[i].position.x, light[i].position.y, light[i].position.z);

        vec3 Al = light[i].ambient;
        vec3 Dl = light[i].diffuse;
        vec3 Sl = light[i].specular;



        vec3 ambient = ka*Al; // Calculem la component ambient


        float d = length(lightPos-tempV); // calculem al distància de la superfície al focus

        // calculem la atenuació a partir de 1/(a + bd + cd^2)
        float atenuacio = 1.0/(light[i].attenuation.x + light[i].attenuation.y*d + light[i].attenuation.z*d*d);

        vec3 L;
        if(light[i].tipus == 0){
            L = normalize(lightPos-tempV); // Normalitzem el vector des de la superfície a la llum
        }else if(light[i].tipus == 1){
            L = normalize(-lightPos); //lightPos sera una direcció si la llum és direccional
        }else{
            L = normalize(lightPos-tempV); // Normalitzem el vector des de la superfície a la llum

            float angleOrigen = degrees(acos(dot(L, light[i].coneDirection)));
            if(angleOrigen > light[i].angle){
                atenuacio = 0.0;
            }
        }

        float diffuseDot = dot(L,tempN); // fem el producte vectorial necessari, assegurant-nos que no hi ha errors
        if(diffuseDot< 0){
            diffuseDot = 0;
        }
        vec3 diffuse = (kd*Dl)*diffuseDot; // Calculem la component difosa



        float beta = InfoMaterial.shine;
        vec3 H = normalize(L+v); // calculem la H
        float specularDot = dot(tempN,H); // fem el producte vectorial necessari, assegurant-nos que no hi ha errors
        if(specularDot < 0){
            specularDot = 0;
        }
        vec3 specular = (ks*Sl)*pow(specularDot,beta); // Calculem la component especular


        //OPCIONAL siluetes
        //float silueta = (1 - dot(tempN,v));
        //c += max(silueta*kd,(ambient + diffuse + specular)*atenuacio);
        c += (ambient + diffuse + specular)*atenuacio;

    }

    color = vec4(c, 1.0);

}
