#include "../include/GameState.h"

GameState::GameState() : gameOver(false), gameRunning(true)
{
}

void GameState::setGameOver()
{
    gameOver = true;
    gameRunning = false;
}

void GameState::setGameRunning()
{
    gameRunning = true;
}

void GameState::reset()
{
    gameOver = false;
    gameRunning = true;
}

bool GameState::isGameOver() const
{
    return gameOver;
}

bool GameState::isGameRunning() const
{
    return gameRunning;
}
