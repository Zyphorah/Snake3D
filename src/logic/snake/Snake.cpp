#include "../../../include/logic/snake/Snake.h"

Snake::Snake(Vector3f startPos, int initialSize, int maxCapacity, CubeRenderer& rendererRef)
    : size(initialSize), growthCounter(0), direction(-20, 0, 0), renderer(rendererRef)
{
    body.resize(maxCapacity);
    renderer.generateCubeMatrix(startPos, body, 20, 500); 
}

void Snake::render(RenderWindow& window)
{
    for(int i = 0; i < size; i++)
    {
        vector<Vector2f> projectionCube = renderer.orthographicProjection(body[i], window);
        renderer.drawLine(projectionCube, window); 
    }
}

vector<vector<Vector3f>>& Snake::getBody()
{
    return body;
}

int& Snake::getSizeRef()
{
    return size;
}

int& Snake::getGrowthRef()
{
    return growthCounter;
}

Vector3f& Snake::getDirectionRef()
{
    return direction;
}

CubeRenderer& Snake::getRenderer()
{
    return renderer;
}

int Snake::getSize() const
{
    return size;
}

Vector3f Snake::getDirection() const
{
    return direction;
}
