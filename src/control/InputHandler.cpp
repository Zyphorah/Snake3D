#include "../../include/control/InputHandler.h"

InputHandler::InputHandler(CommandRegistry& commandRegistry, RenderWindow& renderWindow)
    : registry(commandRegistry), window(renderWindow)
{
}

void InputHandler::handleInput()
{
    Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case Event::Closed:
                window.close();
                break;

            case Event::KeyPressed:
                registry.executePressedCommand(event.key.code);
                break;
            
            case Event::KeyReleased:
                registry.executeReleasedCommand(event.key.code);
                break;

            default:
                break;
        }
    }
}

CommandRegistry& InputHandler::getRegistry()
{
    return registry;
}
