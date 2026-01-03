#ifndef COMMAND_REGISTRY_H
#define COMMAND_REGISTRY_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <map>

using namespace sf;

// Type alias pour les fonctions/lambdas de commande
using CommandFunction = std::function<void()>;

class CommandRegistry
{
private:
    std::map<Keyboard::Key, CommandFunction> pressedCommands;
    std::map<Keyboard::Key, CommandFunction> releasedCommands;

public:
    CommandRegistry();
    ~CommandRegistry();
    
    bool executePressedCommand(Keyboard::Key key);
    bool executeReleasedCommand(Keyboard::Key key);
    // Injecte une commande pour une touche pressée
    template<typename Func>
    void injectCommand(Keyboard::Key key, Func&& lambda)
    {
        pressedCommands[key] = std::forward<Func>(lambda);
    }
    // Injecte une commande pour une touche relâchée
    template<typename Func>
    void injectReleasedCommand(Keyboard::Key key, Func&& lambda)
    {
        releasedCommands[key] = std::forward<Func>(lambda);
    }
        
};

#endif
