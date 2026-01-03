#ifndef MATRIX_OPERATION_H
#define MATRIX_OPERATION_H

#include <SFML/Graphics.hpp>

using namespace sf;

class MatrixOperation
{
    public:
        virtual ~MatrixOperation() = default;
        
        virtual void calculate(Vector3f& point) = 0;
};

#endif
