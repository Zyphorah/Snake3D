#include "../../../include/logic/snake/SnakeCollision.h"
#include "../../../include/GameState.h"

void SnakeCollision::check(Snake& snake, GameState& gameState)
{
    auto& tableauMatrixCube = snake.getBody();
    int tailleSnake = snake.getSize();
    
    for(int i = 1; i < tailleSnake; i++)
    {
        if(tableauMatrixCube[0] == tableauMatrixCube[i])
            gameState.setGameOver();
    }
}
