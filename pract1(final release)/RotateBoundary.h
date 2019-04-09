#ifndef ROTATEBOUNDARY_H
#define ROTATEBOUNDARY_H

#include "TG.h"

class RotateBoundary : public TG
{
public:
    glm::vec3 rotation;
    RotateBoundary(float angle, glm::vec3 axis);
    ~RotateBoundary();

};

#endif // ROTATEBOUNDARY_H

