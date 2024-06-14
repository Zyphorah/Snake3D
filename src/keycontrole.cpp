#include "../include/keycontrole.h"
#include "../include/Matrice3D.h"

void eventKey(RenderWindow& window, Vector3f& pivotPointAxe,Vector3f&directionPivot, Vector3f& direction)
{
    Event event;
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
                    case Keyboard:: Z:
                        pivotPointAxe.y = 0;
                        pivotPointAxe.x = 0;
                        break;
                    case Keyboard::Up:
                        pivotPointAxe.x = -1;
                        directionPivot.x =-1;
                        
                        break;
                    case Keyboard::Down:
                        pivotPointAxe.x = 1;
                        directionPivot.x =1;
                        break;
                    case Keyboard::Left:
                        pivotPointAxe.y = -1;
                        directionPivot.y =-1;
                        break;
                    case Keyboard::Right:
                        pivotPointAxe.y = 1;
                        directionPivot.y =1;
                        break;
                    case Keyboard ::A:
                        direction.x = -20;
                        direction.y = 0;
                        direction.z = 0;
                        break;
                    case Keyboard :: D:
                        direction.x = 20;
                        direction.y = 0;
                        direction.z = 0;
                        break;
                    case Keyboard :: W:
                        direction.y = 0;
                        direction.x = 0;
                        direction.z = -20;
                        break;
                    case Keyboard :: S:
                        direction.y = 0;
                        direction.x = 0;
                        direction.z = 20;
                        break; 
                    case Keyboard :: E:
                        direction.y = 10;
                        direction.x = 0;
                        direction.z = 0;
                        break;
                    case Keyboard :: Q:
                        direction.y = -10;
                        direction.x = 0;
                        direction.z = 0;
                        break;
                }
                break;
            case Event :: KeyReleased:
                switch(event.key.code)
                {
                    case Keyboard::Up:
                        pivotPointAxe.x = 0;
                        
                        break;
                    case Keyboard::Down:
                        pivotPointAxe.x = 0;
                        break;
                    case Keyboard::Left:
                        pivotPointAxe.y = 0;
                        break;
                    case Keyboard::Right:
                        pivotPointAxe.y = 0;
                        break;
                }

        }
    } 
}
