#include "../include/main.h"
#include "../include/CubeRenderer.h"
#include "../include/logic/snake/Snake.h"
#include "../include/logic/snake/SnakeMovement.h"
#include "../include/logic/snake/SnakeCollision.h"
#include "../include/logic/snake/SnakeController.h"
#include "../include/GameMenu.h"
#include "../include/GameState.h"
#include "../include/ScoreDisplay.h"

// Instance globale de CubeRenderer
CubeRenderer cubeRenderer(Vector3f(500, 300, 100));

void generateGridBoundary(vector<Vector3f>& LimiteGrille, Vector3f initCoord, int size)
{
    LimiteGrille.resize(17);
    cubeRenderer.generateCube(LimiteGrille, initCoord, size);
}

void renderSnakeCube(Snake& snake, RenderWindow& window, Vector3f pivotPointAxe, Vector2f& angleRotation, Vector3f& DirectionPivot, vector<vector<Vector3f>> LimiteGrille)
{   
    cubeRenderer.rotateMatrix(LimiteGrille, pivotPointAxe, angleRotation, DirectionPivot);

    vector<Vector2f> grilleCube = cubeRenderer.orthographicProjection(LimiteGrille[0], window);
    cubeRenderer.drawLine(grilleCube, window);
    
    // Créer une copie du corps du serpent pour l'affichage
    // Cela évite de modifier les coordonnées réelles du serpent avec la rotation de la caméra
    vector<vector<Vector3f>> bodyCopy = snake.getBody();
    
    // Appliquer la rotation à la copie
    cubeRenderer.rotateMatrix(bodyCopy, pivotPointAxe, angleRotation, DirectionPivot);
    
    // Dessiner la copie
    for(int i = 0; i < snake.getSize(); i++)
    {
        vector<Vector2f> projectionCube = cubeRenderer.orthographicProjection(bodyCopy[i], window);
        cubeRenderer.drawLine(projectionCube, window); 
    }
}

bool isTimeValid(Time elapsed, int conditionTime)
{
    return elapsed.asMilliseconds() >= conditionTime;
}

void gameLoop(RenderWindow& window, Sprite& backgroundSprite)
{
    Vector2f angleRotation{501, -376};
    Vector3f initCoord{500, 300, 0};

    Snake snake(initCoord, 3, 1000, cubeRenderer);

    int conditionTime = 100;
    sf::Clock clock; 
    sf::Time elapsed;

    vector<vector<Vector3f>> LimiteGrille(1);
    Vector3f initCoordGrille{100, 150, -400};
    generateGridBoundary(LimiteGrille[0], initCoordGrille, 800);

    Vector3f pivotPointAxe{0, 0, 0};
    Vector3f DirectionPivot{1, 1, 0};
    
    // Initialisation du contrôleur
    SnakeController controller(snake, window, pivotPointAxe, DirectionPivot);
    
    // Initialisation du menu et state
    GameMenu gameMenu(window.getSize().x, window.getSize().y);
    GameState gameState;
    
    // Initialisation du score
    ScoreDisplay scoreDisplay(window.getSize().x, window.getSize().y);

    while(window.isOpen() && gameState.isGameRunning())
    {
        window.clear();
        elapsed = clock.getElapsedTime();
        if(isTimeValid(elapsed, conditionTime))
        {
            SnakeMovement::process(snake);
            elapsed = clock.restart(); 
        }

        controller.handleInput();
        SnakeCollision::check(snake, gameState);
        
        if (gameState.isGameOver()) {
            break;
        }
        
        SnakeMovement::teleport(snake);
        
        // Update score display
        scoreDisplay.setScore(snake.getSize());

        window.draw(backgroundSprite);
        renderSnakeCube(snake, window, pivotPointAxe, angleRotation, DirectionPivot, LimiteGrille);
        scoreDisplay.render(window);
        
        // Handle mouse events
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }
             
        window.display();
    }
    
    // Show menu when game is over
    gameMenu.show();
    
    // Lambda for restart callback
    gameMenu.setOnRestartCallback([&]() {
        gameLoop(window, backgroundSprite);
    });
    
    // Lambda for quit callback
    gameMenu.setOnQuitCallback([&]() {
        window.close();
    });
    
    // Menu loop
    while(window.isOpen())
    {
        window.clear();
        window.draw(backgroundSprite);
        renderSnakeCube(snake, window, pivotPointAxe, angleRotation, DirectionPivot, LimiteGrille);
        gameMenu.render(window);
        
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                gameMenu.handleMouseClick(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
            }
            else if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }
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
    sf::Sprite backgroundSprite(textureFond);
    backgroundSprite.setScale(
        float(window.getSize().x) / backgroundSprite.getTexture()->getSize().x,
        float(window.getSize().y) / backgroundSprite.getTexture()->getSize().y
    );

    window.setFramerateLimit(60);
    gameLoop(window, backgroundSprite);
}
