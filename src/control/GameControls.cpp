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
        },
        [&pivotPointAxe]() {
            pivotPointAxe.x = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Down,
        [&pivotPointAxe, &directionPivot]() {
            pivotPointAxe.x = 1;
            directionPivot.x = 1;
        },
        [&pivotPointAxe]() {
            pivotPointAxe.x = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Left,
        [&pivotPointAxe, &directionPivot]() {
            pivotPointAxe.y = -1;
            directionPivot.y = -1;
        },
        [&pivotPointAxe]() {
            pivotPointAxe.y = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Right,
        [&pivotPointAxe, &directionPivot]() {
            pivotPointAxe.y = 1;
            directionPivot.y = 1;
        },
        [&pivotPointAxe]() {
            pivotPointAxe.y = 0;
        }
    );
    
    // Touches de mouvement du serpent - injection simple avec une seule lambda
    registry.injectPressedCommand(
        Keyboard::A,
        [&direction]() {
            direction = Vector3f(-20, 0, 0);
        }
    );
    
    registry.injectPressedCommand(
        Keyboard::D,
        [&direction]() {
            direction = Vector3f(20, 0, 0);
        }
    );
    
    registry.injectPressedCommand(
        Keyboard::W,
        [&direction]() {
            direction = Vector3f(0, 0, -20);
        }
    );
    
    registry.injectPressedCommand(
        Keyboard::S,
        [&direction]() {
            direction = Vector3f(0, 0, 20);
        }
    );
    
    registry.injectPressedCommand(
        Keyboard::E,
        [&direction]() {
            direction = Vector3f(0, 10, 0);
        }
    );
    
    registry.injectPressedCommand(
        Keyboard::Q,
        [&direction]() {
            direction = Vector3f(0, -10, 0);
        }
    );
    
    // Touche de réinitialisation
    registry.injectPressedCommand(
        Keyboard::Z,
        [&pivotPointAxe]() {
            pivotPointAxe = Vector3f(0, 0, 0);
        }
    );
}
