#include "Rotate.h"

Rotate::Rotate(float degrees, vec3 axis): rotation(axis)
{
    matTG = RotateX(degrees * axis.x) * RotateY(degrees * axis.y) * RotateZ(degrees * axis.z);//Rotate(mat4(1.0f), degrees, rotation);
}

Rotate::~Rotate()
{

}
