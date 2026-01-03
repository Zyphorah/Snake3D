#ifndef SCORE_DISPLAY_H
#define SCORE_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class ScoreDisplay {
public:
    ScoreDisplay(int windowWidth, int windowHeight);
    
    void setScore(int score);
    void render(RenderWindow& window);
    
private:
    Text scoreText;
    Font font;
    int windowWidth;
    int windowHeight;
    int currentScore;
    
    void initializeFont();
    void updateScoreText();
};

#endif
