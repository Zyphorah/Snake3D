#include "../../../include/logic/snake/SnakeCollision.h"

void SnakeCollision::check(Snake& snake, sf::RenderWindow& window)
{
    auto& tableauMatrixCube = snake.getBody();
    int tailleSnake = snake.getSize();
    
    for(int i = 1; i < tailleSnake; i++)
    {
        if(tableauMatrixCube[0] == tableauMatrixCube[i])
            window.close();
    }
}
