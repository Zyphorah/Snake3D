#include "../include/keycontrole.h"
#include "../include/Matrice3D.h"

void eventKey(RenderWindow& window, vector<vector<Vector3f>>& tableauDeMatrixCube, Vector3f& pivotPointAxe, Vector3f& direction, Event& event)
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case Event::Closed:
                window.close();
                break;

            case Event::KeyPressed:
                switch (event.key.code)
                {
                    case Keyboard::Up:
                        pivotPointAxe.x = -1;
                        break;
                    case Keyboard::Down:
                        pivotPointAxe.x = 1;
                        break;
                    case Keyboard::Left:
                        pivotPointAxe.y = -1;
                        break;
                    case Keyboard::Right:
                        pivotPointAxe.y = 1;
                        break;
                }
                break;

            case Event::KeyReleased:
                switch (event.key.code)
                {
                    case Keyboard::Up:
                    case Keyboard::Down:
                        pivotPointAxe.x = 0;
                        break;
                    case Keyboard::Left:
                    case Keyboard::Right:
                        pivotPointAxe.y = 0;
                        break;
                }
                break;
        }
    } 
}
