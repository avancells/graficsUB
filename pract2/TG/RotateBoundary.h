#ifndef ROTATEBOUNDARY_H
#define ROTATEBOUNDARY_H

#include "TG.h"

using namespace Common;

class RotateBoundary : public TG
{
public:
    vec3 rotation;
    RotateBoundary(float angle, vec3 axis);
    ~RotateBoundary();

};

#endif // ROTATEBOUNDARY_H

