#ifndef Light_H
#define Light_H

#include "./library/Common.h"

// Tipus de Lights
enum LightType {Puntual, Direccional, Spot};

// Classe que representa els atributs d'una Light
// TO DO: A la fase 1 has d'incloure els atributs necessaris per codificar una llum

class Light {
    public:
        Light(LightType l);

        vec4 getLightPosition();
        void setLightPosition(vec4 v);

        vec3 getIa() const;
        void setIa(const vec3 &value);

        vec3 getId();
        void setId(vec3 i);

        vec3 getIs() const;
        void setIs(const vec3 &value);

        vec3 getCoeficients() const;
        void setCoeficients(const vec3 &value);

        LightType getTipusLight() const;
        void setTipusLight(const LightType &value);

        float getAngleLight() const;
        void setAngleLight(const float &value);

        vec3 getConeLight() const;
        void setConeLight(const vec3 &value);


        vec3 diffuse;
        vec3 ambient;
        vec3 specular;
        vec3 attenuation;
        vec4 position;

        LightType tipus;

        float angle;
        vec3 coneDirection;

};

#endif // Light_H
