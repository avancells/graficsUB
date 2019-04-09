#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Object.h"

#include "Animation.h"
#include "Translate.h"
#include "Rotate.h"
#include "Scale.h"
#include "RotateBoundary.h"
#include "ScaleBoundary.h"

class Triangle: public Object
{
public:
    Triangle(vec3 vA, vec3 vB, vec3 vC, Material *m);
    void setNormal();
    virtual ~Triangle() {}
    virtual bool hit(const Ray& r, float t_min, float t_max, HitInfo& info) const;
    virtual void aplicaTG(TG *t);
private:
    vec3 vA;
    vec3 vB;
    vec3 vC;
    vec3 normal;
};

#endif // TRIANGLE_H
