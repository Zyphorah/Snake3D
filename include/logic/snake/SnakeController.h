#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#include "Snake.h"
#include "../../control/CommandRegistry.h"
#include "../../control/InputHandler.h"
#include <SFML/Graphics.hpp>

class SnakeController {
public:
    SnakeController(Snake& snake, sf::RenderWindow& window, Vector3f& pivotPointAxe, Vector3f& directionPivot);
    void handleInput();

private:
    Snake& snake;
    CommandRegistry registry;
    InputHandler inputHandler;
    Vector3f& pivotPointAxe;
    Vector3f& directionPivot;

    void setupControls();
};

#endif
