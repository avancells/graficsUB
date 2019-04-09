#include "Light.h"

/**
 * @brief Light::Light
 * @param t
 */
Light::Light(LightType t) {
    // TO DO: A canviar a la fase 1 de la practica 2
    this->diffuse = vec3(0.8, 0.8, 0.8);
    this->ambient = vec3(0.2, 0.2, 0.2);
    this->specular = vec3(0.01, 0.01, 0.01);
    this->attenuation = vec3(0.1, 0.1, 0.1);
    this->position = vec4(-0.5, 10.0, 8.5, 1.0);
    this->tipus = t;
    this->angle = 100.0;
    this->coneDirection = vec3(0.0, -1.0, 0.0);

}

/**
 * @brief Light::getDiffuseIntensity
 * @return
 */
vec3 Light::getId() {
    // TO DO: A canviar a la fase 1 de la practica 2
   return(diffuse);
}

/**
 * @brief Light::setId
 * @param i
 */
void Light::setId(vec3 i) {
    // TO DO: A canviar a la fase 1 de la practica 2
    this->diffuse = i;
}

/**
 * @brief Light::getLightPosition
 */
vec4 Light::getLightPosition() {
    // TO DO: A canviar a la fase 1 de la practica 2
    return(position);
}

/**
 * @brief Light::setLightPosition
 * @param v
 */
void Light::setLightPosition(vec4 v) {
    // TO DO: A canviar a la fase 1 de la practica 2
    this->position = v;
}


/**
 * @brief Light::getIa
 * @return
 */
vec3 Light::getIa() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
       return(this->ambient);
}

/**
 * @brief Light::setIa
 * @param value
 */
void Light::setIa(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->ambient = value;
}

/**
 * @brief Light::getIs
 * @return
 */
vec3 Light::getIs() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
       return(this->specular);
}

/**
 * @brief Light::setIs
 * @param value
 */
void Light::setIs(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->specular = value;
}

/**
 * @brief Light::getCoeficients
 * @return
 */
vec3 Light::getCoeficients() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
       return(this->attenuation);
}

/**
 * @brief Light::setCoeficients
 * @param value
 */
void Light::setCoeficients(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->attenuation = value;
}


/**
 * @brief Light::getTipusLight
 *
 */
LightType Light::getTipusLight() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
    return tipus;
}

/**
 * @brief Light::setTipusLight
 * @param value
 */
void Light::setTipusLight(const LightType &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->tipus = value;
}

/**
 * @brief Light::getAngleLight
 *
 */
float Light::getAngleLight() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
    return angle;
}

/**
 * @brief Light::setAngleLight
 * @param value
 */
void Light::setAngleLight(const float &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->angle = value;
}

/**
 * @brief Light::getConeLight
 *
 */
vec3 Light::getConeLight() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
    return coneDirection;
}

/**
 * @brief Light::setConeLight
 * @param value
 */
void Light::setConeLight(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->coneDirection = value;
}
