#include "../include/main.h"
#include "../include/CubeRenderer.h"
#include "../include/logic/snake/Snake.h"
#include "../include/logic/snake/SnakeMovement.h"
#include "../include/logic/snake/SnakeCollision.h"
#include "../include/logic/snake/SnakeController.h"

// Instance globale de CubeRenderer
CubeRenderer cubeRenderer(Vector3f(500, 300, 100));

void générerlimiteGrille(vector<Vector3f>& LimiteGrille, Vector3f initCoord, int taille)
{
    LimiteGrille.resize(17);
    cubeRenderer.genererCube(LimiteGrille, initCoord, taille);
}

void dessinerCube(Snake& snake, RenderWindow& window, Vector3f pivotPointAxe, Vector2f& angleRotation, Vector3f& DirectionPivot, vector<vector<Vector3f>> LimiteGrille)
{   
    cubeRenderer.tableauPivot(LimiteGrille, pivotPointAxe, angleRotation, DirectionPivot);

    vector<Vector2f> grilleCube = cubeRenderer.projectionOrthographique(LimiteGrille[0], window);
    cubeRenderer.dessinerVecteur(grilleCube, window);
    
    // Créer une copie du corps du serpent pour l'affichage
    // Cela évite de modifier les coordonnées réelles du serpent avec la rotation de la caméra
    vector<vector<Vector3f>> bodyCopy = snake.getBody();
    
    // Appliquer la rotation à la copie
    cubeRenderer.tableauPivot(bodyCopy, pivotPointAxe, angleRotation, DirectionPivot);
    
    // Dessiner la copie
    for(int i = 0; i < snake.getSize(); i++)
    {
        vector<Vector2f> projectionCube = cubeRenderer.projectionOrthographique(bodyCopy[i], window);
        cubeRenderer.dessinerVecteur(projectionCube, window); 
    }
}

bool timeValid(Time elapsed, int conditionTime)
{
    return elapsed.asMilliseconds() >= conditionTime;
}

void loopWindow(RenderWindow& window, Sprite& spriteFond)
{
    Vector2f angleRotation{501, -376};
    Vector3f initCoord{500, 300, 0};

    Snake snake(initCoord, 3, 1000, cubeRenderer);

    int conditionTime = 100;
    sf::Clock clock; 
    sf::Time elapsed;

    vector<vector<Vector3f>> LimiteGrille(1);
    Vector3f initCoordGrille{100, 150, -400};
    générerlimiteGrille(LimiteGrille[0], initCoordGrille, 800);

    Vector3f pivotPointAxe{0, 0, 0};
    Vector3f DirectionPivot{1, 1, 0};
    
    // Initialisation du contrôleur
    SnakeController controller(snake, window, pivotPointAxe, DirectionPivot);

    while(window.isOpen())
    {
        window.clear();
        elapsed = clock.getElapsedTime();
        if(timeValid(elapsed, conditionTime))
        {
            SnakeMovement::process(snake);
            elapsed = clock.restart(); 
        }

        controller.handleInput();
        SnakeCollision::check(snake, window);
        SnakeMovement::teleport(snake);

        window.draw(spriteFond);
        dessinerCube(snake, window, pivotPointAxe, angleRotation, DirectionPivot, LimiteGrille);
             
        window.display();
    }
}

int main()
{
    RenderWindow window(VideoMode(1300, 800), "Matrix");  

    Texture textureFond;
    if (!textureFond.loadFromFile("background.png")) {
        // Essai dans le dossier parent
        if (!textureFond.loadFromFile("../background.png")) {
            cout << "Erreur: le fond d'écran ne s'est pas chargé correctement (background.png ou ../background.png introuvable)" << endl;
            return -1;
        } else {
            cout << "Info: background.png non trouvé, mais ../background.png chargé avec succès." << endl;
        }
    }
    sf::Sprite spriteFond(textureFond);
    spriteFond.setScale(
        float(window.getSize().x) / spriteFond.getTexture()->getSize().x,
        float(window.getSize().y) / spriteFond.getTexture()->getSize().y
    );

    window.setFramerateLimit(60);
    loopWindow(window, spriteFond);
}
