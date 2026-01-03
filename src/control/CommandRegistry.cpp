#include "../../include/control/CommandRegistry.h"

CommandRegistry::CommandRegistry()
{
}

CommandRegistry::~CommandRegistry()
{
}

bool CommandRegistry::executePressedCommand(Keyboard::Key key)
{
    return executeCommand(pressedCommands, key);
}

bool CommandRegistry::executeReleasedCommand(Keyboard::Key key)
{
    return executeCommand(releasedCommands, key);
}

bool CommandRegistry::executeCommand(std::map<Keyboard::Key, CommandFunction>& commandMap, Keyboard::Key key)
{
    auto it = commandMap.find(key);
    if (it != commandMap.end() && it->second)
    {
        it->second();
        return true;
    }
    return false;
}
