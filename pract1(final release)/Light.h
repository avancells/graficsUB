#ifndef LIGHT_H
#define LIGHT_H
#include <vector>
#include "glm/glm.hpp"
using namespace glm;

class Light
{
public:
    Light(vec3 position, vec3 Ia, vec3 Id, vec3 Is, float coefAt_a, float coefAt_b, float coefAt_c);
    ~Light(){}
    vec3 position;
    vec3 Ia;
    vec3 Id;
    vec3 Is;
    float coefAt_a;
    float coefAt_b;
    float coefAt_c;



};

#endif // LIGHT_H
