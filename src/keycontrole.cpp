#include "../include/keycontrole.h"
#include "../include/control/CommandRegistry.h"
#include "../include/control/InputHandler.h"
#include "../include/control/GameControls.h"

void eventKey(RenderWindow& window, Vector3f& pivotPointAxe, Vector3f& directionPivot, Vector3f& direction)
{
    // Créer une instance du registre de commandes
    static CommandRegistry registry;
    static InputHandler inputHandler(registry, window);
    
    setupGameControls(registry, pivotPointAxe, directionPivot, direction);
   
    // Traiter les événements d'entrée
    inputHandler.handleInput();
}

