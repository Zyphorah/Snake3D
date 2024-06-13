#include "../include/main.h"
#include "../include/Matrice3D.h"
#include "../include/keycontrole.h"

void dessinerCube(vector<vector<Vector3f>>& tableauMatrixCube,RenderWindow& window)
{
    for(int i = 0; i< tableauMatrixCube.size();i++)
    {
         vector<Vector2f> projectionCube = projectionOrthographique(tableauMatrixCube[i],window);
         dessinerVecteur(projectionCube,window); 
    }    
}

void deplacementSnake(vector<vector<Vector3f>>& tableauMatrixCube)
{
    cout<< "teste";
}

bool timeValid(Time elapsed,int conditionTime)
{
    if(elapsed == conditionTime)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void loopWindow(RenderWindow& window)
{
    //Gestion du temps pour le déplacement snake
    int conditionTime = 1000;
    sf::Clock clock; 
    sf::Time elapsed = clock.restart(); 

    //Stockage du serpent dans un tableau de matrice
    vector<vector<Vector3f>> tableauDeMatrixCube{10};

    //Direction de rotation 
    Vector3f pivotPointAxe{0,0,0};

    //Génération de la forme géométrique
    vector<Vector3f> matrixCube{17};
    Vector3f initCoord{500, 300, 0};

    
    TableauCube(initCoord,tableauDeMatrixCube,20,10);

    tableauDeMatrixCube[0]=matrixCube;

    Event event;
    while(window.isOpen())
    {
       
        window.clear();
        if(timeValid)
        {
            deplacementSnake(tableauDeMatrixCube);
        }
       
        eventKey(window,tableauDeMatrixCube, pivotPointAxe);
        dessinerCube(tableauDeMatrixCube,window);
        tableauPivot(tableauDeMatrixCube,pivotPointAxe);

        window.display();
    }
}

int main()
{
     
    RenderWindow window(VideoMode(1300,800),"Matrix");  
    window.setFramerateLimit(60);
    loopWindow(window);
}