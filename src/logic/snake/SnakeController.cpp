#include "../../../include/logic/snake/SnakeController.h"

SnakeController::SnakeController(Snake& snakeRef, sf::RenderWindow& window, Vector3f& pivotRef, Vector3f& dirPivotRef)
    : snake(snakeRef), inputHandler(registry, window), pivotPointAxe(pivotRef), directionPivot(dirPivotRef)
{
    setupControls();
}

void SnakeController::handleInput()
{
    inputHandler.handleInput();
}

void SnakeController::setupControls()
{
    // Touches de rotation avec flèches
    registry.injectCommand(
        Keyboard::Up,
        [this]() {
            pivotPointAxe.x = -1;
            directionPivot.x = -1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Up,
        [this]() {
            pivotPointAxe.x = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Down,
        [this]() {
            pivotPointAxe.x = 1;
            directionPivot.x = 1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Down,
        [this]() {
            pivotPointAxe.x = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Left,
        [this]() {
            pivotPointAxe.y = -1;
            directionPivot.y = -1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Left,
        [this]() {
            pivotPointAxe.y = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Right,
        [this]() {
            pivotPointAxe.y = 1;
            directionPivot.y = 1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Right,
        [this]() {
            pivotPointAxe.y = 0;
        }
    );
    
    // Touches de mouvement du serpent
    // Note: Using getDirectionRef() to modify direction directly, matching original logic
    
    registry.injectCommand(
        Keyboard::A,
        [this]() {
            snake.getDirectionRef() = Vector3f(-20, 0, 0);
        }
    );
    
    registry.injectCommand(
        Keyboard::D,
        [this]() {
            snake.getDirectionRef() = Vector3f(20, 0, 0);
        }
    );
    
    registry.injectCommand(
        Keyboard::W,
        [this]() {
            snake.getDirectionRef() = Vector3f(0, 0, -20);
        }
    );
    
    registry.injectCommand(
        Keyboard::S,
        [this]() {
            snake.getDirectionRef() = Vector3f(0, 0, 20);
        }
    );
    
    registry.injectCommand(
        Keyboard::E,
        [this]() {
            snake.getDirectionRef() = Vector3f(0, 10, 0);
        }
    );
    
    registry.injectCommand(
        Keyboard::Q,
        [this]() {
            snake.getDirectionRef() = Vector3f(0, -10, 0);
        }
    );
}
