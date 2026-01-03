#include "../../include/matrix/RotationMatrixX.h"

RotationMatrixX::RotationMatrixX(float cosX, float sinX)
    : cosX(cosX), sinX(sinX)
{
}

void RotationMatrixX::calculate(Vector3f& point)
{
    float y = point.y * cosX + point.z * sinX;
    float z = -point.y * sinX + point.z * cosX;
    point.y = y;
    point.z = z;
}
