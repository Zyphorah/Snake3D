#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "../../CubeRenderer.h"

using namespace sf;
using namespace std;

class Snake {
public:
    Snake(Vector3f startPos, int initialSize, int maxCapacity, CubeRenderer& renderer);

    void draw(RenderWindow& window);
    
    // Getters returning references to allow modification by logic classes
    vector<vector<Vector3f>>& getBody();
    int& getSizeRef();
    int& getGrowthRef();
    Vector3f& getDirectionRef();
    CubeRenderer& getRenderer();

    // Const getters
    int getSize() const;
    Vector3f getDirection() const;

private:
    vector<vector<Vector3f>> body;
    int size;
    int growthCounter;
    Vector3f direction;
    CubeRenderer& renderer;
};

#endif
