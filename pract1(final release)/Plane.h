#ifndef PLANE_H
#define PLANE_H

#include "Object.h"
#include "Animation.h"
#include "Translate.h"
#include "Rotate.h"
#include "Scale.h"



class Plane: public Object
{
public:
    Plane(vec3 normal, vec3 punt_de_pas, Material*);
    virtual ~Plane() {}
    virtual bool hit(const Ray& r, float t_min, float t_max, HitInfo& info) const;
    virtual void aplicaTG(TG *t);
private:
    vec3 normal;
    vec3 punt;
    float d;

};

#endif // PLANE_H
