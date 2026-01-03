#include "../include/GameMenu.h"
#include <iostream>

GameMenu::GameMenu(int width, int height)
    : visible(false), windowWidth(width), windowHeight(height)
{
    initializeFont();
    initializeButtons();
}

void GameMenu::initializeFont()
{
    // Try to load a default system font - if it fails, we'll use SFML built-in
    if (!font.loadFromFile("/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf")) {
        if (!font.loadFromFile("arial.ttf")) {
            cerr << "Warning: Could not load font, text will not display properly" << endl;
        }
    }
}

void GameMenu::initializeButtons()
{
    // Game Over Text
    gameOverText.setString("GAME OVER");
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(60);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setPosition(
        windowWidth / 2 - gameOverText.getLocalBounds().width / 2,
        windowHeight / 4
    );
    
    // Restart Button
    restartButton.setSize(Vector2f(200, 60));
    restartButton.setFillColor(Color::Green);
    restartButton.setPosition(
        windowWidth / 2 - 220,
        windowHeight / 2 + 50
    );
    
    restartText.setString("RESTART");
    restartText.setFont(font);
    restartText.setCharacterSize(30);
    restartText.setFillColor(Color::White);
    restartText.setPosition(
        restartButton.getPosition().x + 20,
        restartButton.getPosition().y + 15
    );
    
    // Quit Button
    quitButton.setSize(Vector2f(200, 60));
    quitButton.setFillColor(Color::Red);
    quitButton.setPosition(
        windowWidth / 2 + 20,
        windowHeight / 2 + 50
    );
    
    quitText.setString("QUIT");
    quitText.setFont(font);
    quitText.setCharacterSize(30);
    quitText.setFillColor(Color::White);
    quitText.setPosition(
        quitButton.getPosition().x + 50,
        quitButton.getPosition().y + 15
    );
}

void GameMenu::render(RenderWindow& window)
{
    if (!visible) return;
    
    // Draw semi-transparent overlay
    RectangleShape overlay(Vector2f(windowWidth, windowHeight));
    overlay.setFillColor(Color(0, 0, 0, 150));
    window.draw(overlay);
    
    // Draw text and buttons
    window.draw(gameOverText);
    window.draw(restartButton);
    window.draw(restartText);
    window.draw(quitButton);
    window.draw(quitText);
}

void GameMenu::handleMouseClick(Vector2f mousePos)
{
    if (!visible) return;
    
    if (isMouseOverButton(mousePos, restartButton)) {
        if (onRestartCallback) {
            onRestartCallback();
        }
    } else if (isMouseOverButton(mousePos, quitButton)) {
        if (onQuitCallback) {
            onQuitCallback();
        }
    }
}

bool GameMenu::isMouseOverButton(Vector2f mousePos, const RectangleShape& button) const
{
    return button.getGlobalBounds().contains(mousePos);
}

void GameMenu::show()
{
    visible = true;
}

void GameMenu::hide()
{
    visible = false;
}

bool GameMenu::isVisible() const
{
    return visible;
}

void GameMenu::setOnRestartCallback(function<void()> callback)
{
    onRestartCallback = callback;
}

void GameMenu::setOnQuitCallback(function<void()> callback)
{
    onQuitCallback = callback;
}
