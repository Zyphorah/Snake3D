#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SFML/Graphics.hpp>
#include "CommandRegistry.h"

using namespace sf;

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
