#ifndef KEYCONTROLE_H
#define KEYCONTROLE_H

#include <SFML/Graphics.hpp>

using namespace sf;

// Interface pour gérer les événements d'entrée
// Utilise un registre de commandes avec lambdas
void eventKey(RenderWindow& window, Vector3f& pivotPointAxe, Vector3f& directionPivot, Vector3f& direction);

#endif
