#include "../include/main.h"
#include "../include/Matrice3D.h"
#include "../include/keycontrole.h"

void collision(vector<vector>Vector3f>> tableauMatrixCube)
{
    
}

void dessinerCube(vector<vector<Vector3f>> tableauMatrixCube,RenderWindow& window,int tailleSnake, Vector3f pivotPointAxe,Vector2f& angleRotation,Vector3f&DirectionPivot)
{
    
    tableauPivot(tableauMatrixCube,pivotPointAxe,angleRotation,DirectionPivot);
    for(int i = 0;i<tailleSnake;i++)
    {
         vector<Vector2f> projectionCube = projectionOrthographique(tableauMatrixCube[i],window);
         dessinerVecteur(projectionCube,window); 
    }    
}
void deplacementSnake(vector<vector<Vector3f>>& tableauMatrixCube, int& tailleSnake, Vector3f& direction) 
{
    //Stocker la tête car ont n'a besoins des coordonnées pour la génération de la nouvelle tête
    Vector3f initCoord{tableauMatrixCube[0][0]};

    // Déplacer chaque segment à la position du segment précédent
    for (int i = tailleSnake - 1; i > 0; --i) 
    {
        tableauMatrixCube[i] = tableauMatrixCube[i - 1];
    }

    // Créer un nouveau cube pour la tête du snake dans la nouvelle direction
    initCoord+= direction;
    genererCube(tableauMatrixCube[0],initCoord,20);
}

bool timeValid(Time elapsed,int conditionTime)
{
     return elapsed.asMilliseconds() >= conditionTime;
}

void loopWindow(RenderWindow& window,Event& event)
{
    //Angle de rotation pour la camera.
    Vector2f angleRotation{501,-376};

    //Génération de la forme géométrique
    vector<Vector3f> matrixCube{17};
    Vector3f initCoord{500, 300, 0};

    //Stockage du serpent dans un tableau de matrice
    vector<vector<Vector3f>> tableauDeMatrixCube(500);
    int tailleSnake{10};
    Vector3f direction{-20,0,0};

    //Gestion du temps pour le déplacement snake
    int conditionTime = 1000;
    sf::Clock clock; 
    sf::Time elapsed;

    TableauCube(initCoord,tableauDeMatrixCube,20,500);

    //Direction de rotation 
    Vector3f pivotPointAxe{0,0,0};
    Vector3f DirectionPivot{1,1,0};

    while(window.isOpen())
    {
        window.clear();
        elapsed = clock.getElapsedTime();
        if(timeValid(elapsed,conditionTime))
        {
            deplacementSnake(tableauDeMatrixCube,tailleSnake,direction);
            elapsed = clock.restart(); 
        }
       
        eventKey(window,pivotPointAxe,DirectionPivot,direction);
        dessinerCube(tableauDeMatrixCube,window,tailleSnake,pivotPointAxe,angleRotation,DirectionPivot);
        
        window.display();
    }
}

int main()
{
    Event event;
    RenderWindow window(VideoMode(1300,800),"Matrix");  
    window.setFramerateLimit(60);
    loopWindow(window,event);
}