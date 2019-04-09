#include "Light.h"

Light::Light(vec3 position, vec3 Ia, vec3 Id, vec3 Is, float coefAt_a, float coefAt_b, float coefAt_c)
{
    this->position = position;
    this->Ia = Ia;
    this->Id = Id;
    this->Is = Is;
    this->coefAt_a = coefAt_a;
    this->coefAt_b = coefAt_b;
    this->coefAt_c = coefAt_c;
}

