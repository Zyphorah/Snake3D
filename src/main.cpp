#include "../include/main.h"
#include "../include/Matrice3D.h"
#include "../include/keycontrole.h"

void teleportTeteSnake(vector<vector<Vector3f>>& SnakeCorps)
{
    Vector3f& pos = SnakeCorps[0][0];
    
    // Téléportation sur axe X
    if(pos.x < 100) pos.x = 880;
    else if(pos.x > 880) pos.x = 100;
    // Téléportation sur axe Y
    else if(pos.y > 550) pos.y = 150;
    else if(pos.y < 150) pos.y = 550;
    // Téléportation sur axe Z
    else if(pos.z < -400) pos.z = 380;
    else if(pos.z > 380) pos.z = -400;
    else return;
    
    genererCube(SnakeCorps[0], pos, 20);
}

void générerlimiteGrille(vector<Vector3f>& LimiteGrille, Vector3f initCoord, int taille)
{
    LimiteGrille.resize(17);
    genererCube(LimiteGrille, initCoord, taille);
}

void collision(vector<vector<Vector3f>> tableauMatrixCube, RenderWindow& window, int tailleSnake)
{
    for(int i = 1; i < tailleSnake; i++)
    {
        if(tableauMatrixCube[0] == tableauMatrixCube[i])
            window.close();
    }
}

void dessinerCube(vector<vector<Vector3f>> tableauMatrixCube, RenderWindow& window, int tailleSnake, Vector3f pivotPointAxe, Vector2f& angleRotation, Vector3f& DirectionPivot, vector<vector<Vector3f>> LimiteGrille)
{   
    tableauPivot(tableauMatrixCube, pivotPointAxe, angleRotation, DirectionPivot);
    tableauPivot(LimiteGrille, pivotPointAxe, angleRotation, DirectionPivot);

    vector<Vector2f> grilleCube = projectionOrthographique(LimiteGrille[0], window);
    dessinerVecteur(grilleCube, window);
    
    for(int i = 0; i < tailleSnake; i++)
    {
        vector<Vector2f> projectionCube = projectionOrthographique(tableauMatrixCube[i], window);
        dessinerVecteur(projectionCube, window); 
    }    
}

void deplacementSnake(vector<vector<Vector3f>>& tableauMatrixCube, int& tailleSnake, Vector3f& direction, int& grandirSnake) 
{
    Vector3f initCoord = tableauMatrixCube[0][0];

    for (int i = tableauMatrixCube.size() - 1; i > 0; --i) 
        tableauMatrixCube[i] = tableauMatrixCube[i - 1];

    initCoord += direction;
    genererCube(tableauMatrixCube[0], initCoord, 20);
    
    if(++grandirSnake == 4)
    {
        tailleSnake++;
        grandirSnake = 0;
    }
}

bool timeValid(Time elapsed, int conditionTime)
{
    return elapsed.asMilliseconds() >= conditionTime;
}

void loopWindow(RenderWindow& window, Sprite& spriteFond)
{
    Vector2f angleRotation{501, -376};
    vector<Vector3f> matrixCube{17};
    Vector3f initCoord{500, 300, 0};

    vector<vector<Vector3f>> tableauDeMatrixCube(1000);
    int tailleSnake{3};
    int grandirSnake{0};
    Vector3f direction{-20, 0, 0};

    int conditionTime = 100;
    sf::Clock clock; 
    sf::Time elapsed;

    TableauCube(initCoord, tableauDeMatrixCube, 20, 500);

    vector<vector<Vector3f>> LimiteGrille(1);
    Vector3f initCoordGrille{100, 150, -400};
    générerlimiteGrille(LimiteGrille[0], initCoordGrille, 800);

    Vector3f pivotPointAxe{0, 0, 0};
    Vector3f DirectionPivot{1, 1, 0};

    while(window.isOpen())
    {
        window.clear();
        elapsed = clock.getElapsedTime();
        if(timeValid(elapsed, conditionTime))
        {
            deplacementSnake(tableauDeMatrixCube, tailleSnake, direction, grandirSnake);
            elapsed = clock.restart(); 
        }

        eventKey(window, pivotPointAxe, DirectionPivot, direction);
        collision(tableauDeMatrixCube, window, tailleSnake);
        teleportTeteSnake(tableauDeMatrixCube);

        window.draw(spriteFond);
        dessinerCube(tableauDeMatrixCube, window, tailleSnake, pivotPointAxe, angleRotation, DirectionPivot, LimiteGrille);
             
        window.display();
    }
}

int main()
{
    RenderWindow window(VideoMode(1300, 800), "Matrix");  

    Texture textureFond;
    if (!textureFond.loadFromFile("background.png")) 
    {
        cout << "Erreur: le fond d'écran ne s'est pas chargé correctement" << endl;
        return -1;
    }
    
    sf::Sprite spriteFond(textureFond);
    spriteFond.setScale(
        float(window.getSize().x) / spriteFond.getTexture()->getSize().x,
        float(window.getSize().y) / spriteFond.getTexture()->getSize().y
    );

    window.setFramerateLimit(60);
    loopWindow(window, spriteFond);
}
