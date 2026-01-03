#include "../../../include/logic/snake/SnakeMovement.h"

void SnakeMovement::process(Snake& snake)
{
    auto& tableauMatrixCube = snake.getBody();
    int& tailleSnake = snake.getSizeRef();
    Vector3f& direction = snake.getDirectionRef();
    int& grandirSnake = snake.getGrowthRef();
    CubeRenderer& cubeRenderer = snake.getRenderer();

    Vector3f initCoord = tableauMatrixCube[0][0];

    for (int i = tableauMatrixCube.size() - 1; i > 0; --i) 
        tableauMatrixCube[i] = tableauMatrixCube[i - 1];

    initCoord += direction;
    cubeRenderer.genererCube(tableauMatrixCube[0], initCoord, 20);
    
    if(++grandirSnake == 4)
    {
        tailleSnake++;
        grandirSnake = 0;
    }
}

void SnakeMovement::teleport(Snake& snake)
{
    auto& SnakeCorps = snake.getBody();
    CubeRenderer& cubeRenderer = snake.getRenderer();

    Vector3f& pos = SnakeCorps[0][0];
    
    // Téléportation sur axe X
    if(pos.x < 100) pos.x = 880;
    else if(pos.x > 880) pos.x = 100;
    // Téléportation sur axe Y
    else if(pos.y > 550) pos.y = 150;
    else if(pos.y < 150) pos.y = 550;
    // Téléportation sur axe Z
    else if(pos.z < -400) pos.z = 380;
    else if(pos.z > 380) pos.z = -400;
    else return;
    
    cubeRenderer.genererCube(SnakeCorps[0], pos, 20);
}
