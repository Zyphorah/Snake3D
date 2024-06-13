#include "../include/keycontrole.h"
#include "../include/Matrice3D.h"

void eventKey(RenderWindow& window,vector<vector<Vector3f>>& tableauDeMatrixCube,Vector3f& pivotPointAxe,Event& event)
{
    while (window.pollEvent(event))
    {
        if(event.type == Event::Closed)
        {
            window.close();
        } 
        else if(event.type == Event :: KeyPressed)
          {

          //Rotation pivot
          if(Keyboard::isKeyPressed(Keyboard::Up))  
          {
            pivotPointAxe.x = -1;     
          }
          if(Keyboard::isKeyPressed(Keyboard::Down))  
          {
            pivotPointAxe.x = 1;  
          }
          if(Keyboard::isKeyPressed(Keyboard::Left))  
          {
            pivotPointAxe.y = -1;  
          }
          if(Keyboard::isKeyPressed(Keyboard::Right))  
          {
            pivotPointAxe.y = 1;  
          }
          }
          else if(event.type == Event::KeyReleased)
          {
            if(event.key.code == Keyboard::Up || event.key.code == Keyboard::Down)
            {
              pivotPointAxe.x = 0;
            }
            if(event.key.code == Keyboard::Left || event.key.code == Keyboard::Right)
            {
              pivotPointAxe.y = 0;
            }
          }
    
    } 
}