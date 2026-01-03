#ifndef GAME_MENU_H
#define GAME_MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

using namespace sf;
using namespace std;

class GameMenu {
public:
    GameMenu(int windowWidth, int windowHeight);
    
    void render(RenderWindow& window);
    void handleMouseClick(Vector2f mousePos);
    void show();
    void hide();
    bool isVisible() const;
    
    // Callback functions
    void setOnRestartCallback(function<void()> callback);
    void setOnQuitCallback(function<void()> callback);
    
private:
    bool visible;
    int windowWidth;
    int windowHeight;
    
    RectangleShape restartButton;
    RectangleShape quitButton;
    Text restartText;
    Text quitText;
    Text gameOverText;
    Font font;
    
    function<void()> onRestartCallback;
    function<void()> onQuitCallback;
    
    void initializeFont();
    void initializeButtons();
    bool isMouseOverButton(Vector2f mousePos, const RectangleShape& button) const;
};

#endif
