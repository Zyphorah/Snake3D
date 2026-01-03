#include "../../include/matrix/RotationMatrixY.h"

RotationMatrixY::RotationMatrixY(float cosY, float sinY)
    : cosY(cosY), sinY(sinY)
{
}

void RotationMatrixY::calculate(Vector3f& point)
{
    float x = point.x * cosY + point.z * sinY;
    float z = -point.x * sinY + point.z * cosY;
    point.x = x;
    point.z = z;
}
