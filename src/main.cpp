#include "../include/main.h"
#include "../include/Matrice3D.h"
#include "../include/keycontrole.h"

void translation(vector<Vector3f>& points, const Vector3f& vecteurTranslation) 
{
    for (auto& point : points) 
     {
        point.x += vecteurTranslation.x;
        point.y += vecteurTranslation.y;
        point.z += vecteurTranslation.z;
    }
}


void dessinerCube(vector<vector<Vector3f>>& tableauMatrixCube,RenderWindow& window,int tailleSnake)
{
    for(int i = 0;i<tailleSnake;i++)
    {
         vector<Vector2f> projectionCube = projectionOrthographique(tableauMatrixCube[i],window);
         dessinerVecteur(projectionCube,window); 
    }    
}

void deplacementSnake(vector<vector<Vector3f>>& tableauMatrixCube,int& tailleSnake,Vector3f& direction)
{
    
    // Vector3f initCoord{tableauMatrixCube[0][0]};
    // initCoord+= direction;
    //genererCube(tableauMatrixCube[0],initCoord,20);
}

bool timeValid(Time elapsed,int conditionTime)
{
     return elapsed.asMilliseconds() >= conditionTime;
}

void loopWindow(RenderWindow& window)
{
    //Direction de rotation 
    Vector3f pivotPointAxe{0,0,0};
    //Génération de la forme géométrique
    vector<Vector3f> matrixCube{17};
    Vector3f initCoord{500, 300, 0};

    RepereLocal repere; // Ajout du repère local
    initialiserRepereLocal(repere,initCoord); // 

    //Stockage du serpent dans un tableau de matrice
    vector<vector<Vector3f>> tableauDeMatrixCube(500);
    int tailleSnake{10};
    Vector3f directionSnake{0,0,0};

    //Gestion du temps pour le déplacement snake
    int conditionTime = 1000;
    sf::Clock clock; 
    sf::Time elapsed;

    TableauCube(initCoord,tableauDeMatrixCube,20,500);

    Event event;
    while(window.isOpen())
    {
       
        window.clear();
        elapsed = clock.getElapsedTime();
        if(timeValid(elapsed,conditionTime))
        {
            deplacementSnake(tableauDeMatrixCube,tailleSnake,directionSnake);
            elapsed = clock.restart(); 
        }
       
        eventKey(window,tableauDeMatrixCube,pivotPointAxe,directionSnake,event);
        dessinerCube(tableauDeMatrixCube,window,tailleSnake);
        tableauPivot(tableauDeMatrixCube, pivotPointAxe, repere);

        window.display();
    }
}

int main()
{
     
    RenderWindow window(VideoMode(1300,800),"Matrix");  
    window.setFramerateLimit(60);
    loopWindow(window);
}