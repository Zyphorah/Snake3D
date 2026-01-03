#ifndef COMMAND_REGISTRY_H
#define COMMAND_REGISTRY_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <map>

using namespace sf;

// Type alias pour les fonctions/lambdas de commande
using CommandFunction = std::function<void()>;

/**
 * CommandRegistry : Registre centralisé pour la gestion des commandes
 * Utilise un dictionnaire de lambdas pour chaque action clavier
 */
class CommandRegistry
{
private:
    // Dictionnaire mappant les touches aux commandes pressées
    std::map<Keyboard::Key, CommandFunction> pressedCommands;
    
    // Dictionnaire mappant les touches aux commandes relâchées
    std::map<Keyboard::Key, CommandFunction> releasedCommands;

    // Méthode interne pour exécuter une commande du dictionnaire
    bool executeCommand(std::map<Keyboard::Key, CommandFunction>& commandMap, Keyboard::Key key);
    
    // Méthode interne pour récupérer une commande du dictionnaire
    CommandFunction* getCommand(std::map<Keyboard::Key, CommandFunction>& commandMap, Keyboard::Key key);

public:
    CommandRegistry();
    ~CommandRegistry();
    
    // Récupère et exécute la commande associée à une touche pressée
    bool executePressedCommand(Keyboard::Key key);
    
    // Récupère et exécute la commande associée à une touche relâchée
    bool executeReleasedCommand(Keyboard::Key key);
    
    // Injecte une commande directement avec une lambda (touche pressée)
    template<typename Func>
    void injectPressedCommand(Keyboard::Key key, Func&& lambda)
    {
        pressedCommands[key] = std::forward<Func>(lambda);
    }
    
    // Injecte une commande directement avec une lambda (touche relâchée)
    template<typename Func>
    void injectReleasedCommand(Keyboard::Key key, Func&& lambda)
    {
        releasedCommands[key] = std::forward<Func>(lambda);
    }
    
    // Injecte une commande directement avec une lambda (pressée et relâchée)
    template<typename FuncPressed, typename FuncReleased>
    void injectCommand(Keyboard::Key key, FuncPressed&& pressedLambda, FuncReleased&& releasedLambda)
    {
        injectPressedCommand(key, std::forward<FuncPressed>(pressedLambda));
        injectReleasedCommand(key, std::forward<FuncReleased>(releasedLambda));
    }
    
    // Variante sans lambda relâchée
    template<typename Func>
    void injectCommand(Keyboard::Key key, Func&& lambda)
    {
        injectPressedCommand(key, std::forward<Func>(lambda));
    }
};

#endif
