#include "ScaleBoundary.h"

ScaleBoundary::ScaleBoundary(vec3 sc): scalation(sc)
{
    matTG = Scale(sc);
}
