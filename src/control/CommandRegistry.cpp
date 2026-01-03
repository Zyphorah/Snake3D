#include "../../include/control/CommandRegistry.h"

CommandRegistry::CommandRegistry()
{
}

CommandRegistry::~CommandRegistry()
{
}

// Suppression de la méthode executeCommand, non utilisée

bool CommandRegistry::executePressedCommand(Keyboard::Key key)
{
    auto it = pressedCommands.find(key);
    if (it != pressedCommands.end() && it->second)
    {
        it->second();
        return true;
    }
    return false;
}

bool CommandRegistry::executeReleasedCommand(Keyboard::Key key)
{
    auto it = releasedCommands.find(key);
    if (it != releasedCommands.end() && it->second)
    {
        it->second();
        return true;
    }
    return false;
}
