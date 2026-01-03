#ifndef ROTATION_MATRIX_Y_H
#define ROTATION_MATRIX_Y_H

#include "MatrixOperation.h"

class RotationMatrixY : public MatrixOperation
{
    private:
        float cosY;
        float sinY;

    public:

        RotationMatrixY(float cosY, float sinY);
        
        void calculate(Vector3f& point) override;
};

#endif
