#ifndef ROTATE_H
#define ROTATE_H

#include "TG.h"

class Rotate : public TG
{
public:
    glm::vec3 rotation;
    Rotate(float angle, glm::vec3 axis);
    ~Rotate();

};

#endif // ROTATE_H

