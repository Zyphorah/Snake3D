#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SFML/Graphics.hpp>
#include "CommandRegistry.h"

using namespace sf;

/**
 * InputHandler : Gestionnaire d'entrées utilisant le registre de commandes
 * S'occupe de traduire les événements SFML en commandes via le registre
 */
class InputHandler
{
private:
    CommandRegistry& registry;
    RenderWindow& window;

public:
    InputHandler(CommandRegistry& commandRegistry, RenderWindow& renderWindow);
    
    void handleInput();
    
    CommandRegistry& getRegistry();
};

#endif
