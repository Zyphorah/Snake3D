#ifndef ROTATION_MATRIX_X_H
#define ROTATION_MATRIX_X_H

#include "MatrixOperation.h"

class RotationMatrixX : public MatrixOperation
{
private:
    float cosX;
    float sinX;

public:

    RotationMatrixX(float cosX, float sinX);

    void calculate(Vector3f& point) override;
};

#endif
