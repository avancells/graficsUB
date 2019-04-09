#ifndef SCALE_H
#define SCALE_H

#include "TG.h"

class Scale : public TG
{
public:
    Scale(glm::vec3 sc);
    ~Scale();
    glm::vec3 scalation;
};

#endif // SCALE_H
