#ifndef GAME_STATE_H
#define GAME_STATE_H

class GameState {
public:
    GameState();
    
    void setGameOver();
    void setGameRunning();
    void reset();
    
    bool isGameOver() const;
    bool isGameRunning() const;
    
private:
    bool gameOver;
    bool gameRunning;
};

#endif
