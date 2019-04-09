#include "ScaleBoundary.h"

ScaleBoundary::ScaleBoundary(glm::vec3 sc): scalation(sc)
{
    matTG = glm::scale(glm::mat4(1.0f), sc);
}
