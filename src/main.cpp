#include "../include/main.h"
#include "../include/Matrice3D.h"
#include "../include/keycontrole.h"

void teleportTeteSnake(vector<vector<Vector3f>>& SnakeCorps)
{
    Vector3f initCoord = SnakeCorps[0][0];
    if(SnakeCorps[0][0].x<100)
    {
        initCoord.x = 880;
        genererCube(SnakeCorps[0],initCoord,20);
    }
    if(SnakeCorps[0][0].x>880)
    {
        initCoord.x = 100;
        genererCube(SnakeCorps[0],initCoord,20);
    }

    if(SnakeCorps[0][0].y>550)
    {
        initCoord.y = 150;
        genererCube(SnakeCorps[0],initCoord,20);
    }
    if(SnakeCorps[0][0].y<150)
    {
        initCoord.y = 550;
        genererCube(SnakeCorps[0],initCoord,20);
    }

    if(SnakeCorps[0][0].z<-400)
    {
        initCoord.z = 380;
        genererCube(SnakeCorps[0],initCoord,20);
    }
    if(SnakeCorps[0][0].z>380)
    {
        initCoord.z = -400;
        genererCube(SnakeCorps[0],initCoord,20);
    }
}

void générerlimiteGrille(vector<Vector3f>& LimiteGrille,Vector3f initCoord,int taille)
{
     LimiteGrille.resize(17);
     genererCube(LimiteGrille,initCoord,taille);
}

void collision(vector<vector<Vector3f>>tableauMatrixCube,RenderWindow&window,int tailleSnake)
{
    for(int i = 1; i<tailleSnake;i++)
    {
        //Regarder Si là tête n'est pas en contacte avec le corp
        if(tableauMatrixCube[0] == tableauMatrixCube[i])
        {
            window.close();
        }
    }
}

void dessinerCube(vector<vector<Vector3f>> tableauMatrixCube,RenderWindow& window,int tailleSnake, Vector3f pivotPointAxe,Vector2f& angleRotation,Vector3f&DirectionPivot,vector<vector<Vector3f>> LimiteGrille)
{   
    tableauPivot(tableauMatrixCube,pivotPointAxe,angleRotation,DirectionPivot);
    

    //Dessiner la grille du jeux
    tableauPivot(LimiteGrille,pivotPointAxe,angleRotation,DirectionPivot);

    vector<Vector2f> grilleCube = projectionOrthographique(LimiteGrille[0], window);
    dessinerVecteur(grilleCube,window);
    

    for(int i = 0;i<tailleSnake;i++)
    {
         vector<Vector2f> projectionCube = projectionOrthographique(tableauMatrixCube[i],window);
         dessinerVecteur(projectionCube,window); 
    }    
}
void deplacementSnake(vector<vector<Vector3f>>& tableauMatrixCube, int& tailleSnake, Vector3f& direction,int& grandirSnake) 
{
    //Stocker la tête car ont n'a besoins des coordonnées pour la génération de la nouvelle tête
    Vector3f initCoord{tableauMatrixCube[0][0]};

    // Déplacer chaque segment à la position du segment précédent
    for (int i = tableauMatrixCube.size()-1; i > 0; --i) 
    {
        tableauMatrixCube[i] = tableauMatrixCube[i - 1];
    }

    // Créer un nouveau cube pour la tête du snake dans la nouvelle direction
    initCoord+= direction;
    genererCube(tableauMatrixCube[0],initCoord,20);
    grandirSnake++;
    if(grandirSnake == 4)
    {
        tailleSnake++;
        grandirSnake=0;
    }

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
    vector<vector<Vector3f>> tableauDeMatrixCube(1000);
    int tailleSnake{3};

    //Utiliser pour gérer le temps, incrémentation chaque seconde
    int grandirSnake{0};
    Vector3f direction{-20,0,0};

    //Gestion du temps pour le déplacement snake
    int conditionTime = 100;
    sf::Clock clock; 
    sf::Time elapsed;

    //Générer le corp du serpents 
    TableauCube(initCoord,tableauDeMatrixCube,20,500);

    //Générer la limite de la grille
    vector<vector<Vector3f>> LimiteGrille(1);
    Vector3f initCoordGrille{100,150,-400};
    int taille{800};
    générerlimiteGrille(LimiteGrille[0],initCoordGrille,taille);

    //Direction de rotation 
    Vector3f pivotPointAxe{0,0,0};
    Vector3f DirectionPivot{1,1,0};

    while(window.isOpen())
    {
        window.clear();
        elapsed = clock.getElapsedTime();
        if(timeValid(elapsed,conditionTime))
        {
            deplacementSnake(tableauDeMatrixCube,tailleSnake,direction,grandirSnake);
            elapsed = clock.restart(); 
        }

        eventKey(window,pivotPointAxe,DirectionPivot,direction);
        collision(tableauDeMatrixCube,window,tailleSnake);
        teleportTeteSnake(tableauDeMatrixCube);
        dessinerCube(tableauDeMatrixCube,window,tailleSnake,pivotPointAxe,angleRotation,DirectionPivot,LimiteGrille);

       
        
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