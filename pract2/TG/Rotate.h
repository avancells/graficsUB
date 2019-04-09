#ifndef ROTATE_H
#define ROTATE_H

#include "TG.h"

using namespace Common;

class Rotate : public TG
{
public:
    vec3 rotation;
    Rotate(float angle, vec3 axis);
    ~Rotate();

};

#endif // ROTATE_H

