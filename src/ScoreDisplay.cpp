#include "../include/ScoreDisplay.h"
#include <iostream>

ScoreDisplay::ScoreDisplay(int width, int height)
    : windowWidth(width), windowHeight(height), currentScore(3)
{
    initializeFont();
    updateScoreText();
}

void ScoreDisplay::initializeFont()
{
    // Try to load a default system font
    if (!font.loadFromFile("/usr/share/fonts/truetype/liberation/LiberationSans-Bold.ttf")) {
        if (!font.loadFromFile("arial.ttf")) {
            cerr << "Warning: Could not load font for score display" << endl;
        }
    }
}

void ScoreDisplay::updateScoreText()
{
    scoreText.setString("Size: " + to_string(currentScore));
    scoreText.setFont(font);
    scoreText.setCharacterSize(35);
    scoreText.setFillColor(Color::White);
    scoreText.setOutlineThickness(2);
    scoreText.setOutlineColor(Color::Black);
    
    // Position in top right corner
    scoreText.setPosition(
        windowWidth - scoreText.getLocalBounds().width - 20,
        20
    );
}

void ScoreDisplay::setScore(int score)
{
    if (currentScore != score) {
        currentScore = score;
        updateScoreText();
    }
}

void ScoreDisplay::render(RenderWindow& window)
{
    window.draw(scoreText);
}
