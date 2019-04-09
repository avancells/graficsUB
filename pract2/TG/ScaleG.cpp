#include "ScaleG.h"

ScaleG::ScaleG(vec3 sc): scalation(sc)
{
    matTG = Scale(sc);
}
