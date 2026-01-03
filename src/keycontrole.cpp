#include "../include/keycontrole.h"
#include "../include/control/CommandRegistry.h"
#include "../include/control/InputHandler.h"
#include "../include/control/GameControls.h"

void eventKey(RenderWindow& window, Vector3f& pivotPointAxe, Vector3f& directionPivot, Vector3f& direction)
{
    // Créer une instance du registre de commandes
    static CommandRegistry registry;
    static InputHandler inputHandler(registry, window);
    static bool initialized = false;
    
    // Initialiser le registre une seule fois avec les contrôles du jeu
    if (!initialized)
    {
        setupGameControls(registry, pivotPointAxe, directionPivot, direction);
        initialized = true;
    }
    
    // Traiter les événements d'entrée
    inputHandler.handleInput();
}

