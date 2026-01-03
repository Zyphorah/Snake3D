#ifndef GAME_CONTROLS_H
#define GAME_CONTROLS_H

#include "CommandRegistry.h"
#include <SFML/Graphics.hpp>

using namespace sf;

void setupGameControls(CommandRegistry& registry, 
                       Vector3f& pivotPointAxe, 
                       Vector3f& directionPivot, 
                       Vector3f& direction);

#endif
