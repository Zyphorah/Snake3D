#include "../../include/control/GameControls.h"

void setupGameControls(CommandRegistry& registry, 
                       Vector3f& pivotPointAxe, 
                       Vector3f& directionPivot, 
                       Vector3f& direction)
{
    // Touches de rotation avec flèches - injection de lambdas
    registry.injectCommand(
        Keyboard::Up,
        [&pivotPointAxe, &directionPivot]() {
            pivotPointAxe.x = -1;
            directionPivot.x = -1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Up,
        [&pivotPointAxe]() {
            pivotPointAxe.x = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Down,
        [&pivotPointAxe, &directionPivot]() {
            pivotPointAxe.x = 1;
            directionPivot.x = 1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Down,
        [&pivotPointAxe]() {
            pivotPointAxe.x = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Left,
        [&pivotPointAxe, &directionPivot]() {
            pivotPointAxe.y = -1;
            directionPivot.y = -1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Left,
        [&pivotPointAxe]() {
            pivotPointAxe.y = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Right,
        [&pivotPointAxe, &directionPivot]() {
            pivotPointAxe.y = 1;
            directionPivot.y = 1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Right,
        [&pivotPointAxe]() {
            pivotPointAxe.y = 0;
        }
    );
    
    // Touches de mouvement du serpent - injection simple avec une seule lambda
    registry.injectCommand(
        Keyboard::A,
        [&direction]() {
            direction = Vector3f(-20, 0, 0);
        }
    );
    
    registry.injectCommand(
        Keyboard::D,
        [&direction]() {
            direction = Vector3f(20, 0, 0);
        }
    );
    
    registry.injectCommand(
        Keyboard::W,
        [&direction]() {
            direction = Vector3f(0, 0, -20);
        }
    );
    
    registry.injectCommand(
        Keyboard::S,
        [&direction]() {
            direction = Vector3f(0, 0, 20);
        }
    );
    
    registry.injectCommand(
        Keyboard::E,
        [&direction]() {
            direction = Vector3f(0, 10, 0);
        }
    );
    
    registry.injectCommand(
        Keyboard::Q,
        [&direction]() {
            direction = Vector3f(0, -10, 0);
        }
    );
}
