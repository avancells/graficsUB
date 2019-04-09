#ifndef SCALEBOUNDARY_H
#define SCALEBOUNDARY_H

#include "TG.h"

using namespace Common;

class ScaleBoundary : public TG
{
public:
    ScaleBoundary(vec3 sc);
    ~ScaleBoundary();
    vec3 scalation;
};

#endif // SCALEBOUNDARY_H
