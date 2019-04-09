#include "Scale.h"

Scale::Scale(glm::vec3 sc): scalation(sc)
{
    matTG = glm::scale(glm::mat4(1.0f), sc);
}
