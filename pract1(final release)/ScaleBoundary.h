#ifndef SCALEBOUNDARY_H
#define SCALEBOUNDARY_H

#include "TG.h"

class ScaleBoundary : public TG
{
public:
    ScaleBoundary(glm::vec3 sc);
    ~ScaleBoundary();
    glm::vec3 scalation;
};

#endif // SCALEBOUNDARY_H
