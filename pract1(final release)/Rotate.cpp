#include "Rotate.h"

Rotate::Rotate(float degrees, glm::vec3 axis): rotation(axis)
{
    matTG = glm::rotate(glm::mat4(1.0f), degrees, rotation);
}

Rotate::~Rotate()
{

}
