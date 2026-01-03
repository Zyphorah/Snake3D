#ifndef SNAKE_MOVEMENT_H
#define SNAKE_MOVEMENT_H

#include "Snake.h"

class SnakeMovement {
public:
    static void process(Snake& snake);
    static void teleport(Snake& snake);
};

#endif
