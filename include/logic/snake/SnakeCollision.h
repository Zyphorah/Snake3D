#ifndef SNAKE_COLLISION_H
#define SNAKE_COLLISION_H

#include "Snake.h"
#include <SFML/Graphics.hpp>

class SnakeCollision {
public:
    static void check(Snake& snake, sf::RenderWindow& window);
};

#endif
