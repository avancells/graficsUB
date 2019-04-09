#ifndef SCALEG_H
#define SCALEG_H

#include "TG.h"

using namespace Common;

class ScaleG : public TG
{
public:
    ScaleG(vec3 sc);
    ~ScaleG();
    vec3 scalation;
};

#endif // SCALEG_H
