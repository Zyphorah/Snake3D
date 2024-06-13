#include "../include/keycontrole.h"
#include "../include/Matrice3D.h"



void eventKey(RenderWindow& window,vector<vector<Vector3f>>& tableauDeMatrixCube,Vector3f& pivotPointAxe)
{

    Event event;
    while (window.pollEvent(event))
    {
        if(event.type == Event::Closed)
        {
            window.close();
        } 
        else if(event.type == Event :: KeyPressed)
          {

            if(Keyboard :: isKeyPressed(Keyboard :: S))
            {
                
            }
            if(Keyboard :: isKeyPressed(Keyboard :: W))
            {
                
            }

             if(Keyboard :: isKeyPressed(Keyboard :: S))
            {
                
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                
            }

            //Rotation pivot
          if(Keyboard::isKeyPressed(Keyboard::Up))  
          {
            pivotPointAxe.x = -1;     
          }
          else if(Keyboard::isKeyPressed(Keyboard::Down))  
          {
            pivotPointAxe.x = 1;  
          }
          else if(Keyboard::isKeyPressed(Keyboard::Left))  
          {
            pivotPointAxe.y = -1;  
          }
          else if(Keyboard::isKeyPressed(Keyboard::Right))  
          {
            pivotPointAxe.y = 1;  
          }
          }
           else if(event.type == sf::Event::KeyReleased)
          {
            if(Keyboard::Up||Keyboard::Down)
            {
                pivotPointAxe.x = 0;
            }
            if(Keyboard::Left||Keyboard::Right)
            {
                pivotPointAxe.y = 0;
            }

          }

         
    } 
}