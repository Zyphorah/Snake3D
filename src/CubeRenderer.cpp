#include "../include/CubeRenderer.h"
#include "../include/matrix/Rotation/RotationMatrixX.h"
#include "../include/matrix/Rotation/RotationMatrixY.h"

CubeRenderer::CubeRenderer(const Vector3f& centre)
    : rotationCentre(centre)
{
}

void CubeRenderer::genererCube(vector<Vector3f>& matrixCube, Vector3f& initCoord, int taille)
{
    matrixCube[0] = initCoord;
    matrixCube[1] = matrixCube[0] + Vector3f(taille, 0, 0);
    matrixCube[2] = matrixCube[1] + Vector3f(0, taille/2, 0);
    matrixCube[3] = matrixCube[2] + Vector3f(-taille, 0, 0);
    matrixCube[4] = initCoord;

    for(int i = 5; i <= 9; i++)
        matrixCube[i] = matrixCube[i-5] + Vector3f(0, 0, taille);

    matrixCube[10] = matrixCube[0];
    matrixCube[11] = matrixCube[1];
    matrixCube[12] = matrixCube[6];
    matrixCube[13] = matrixCube[7];
    matrixCube[14] = matrixCube[2];
    matrixCube[15] = matrixCube[3];
    matrixCube[16] = matrixCube[8];
}

vector<Vector2f> CubeRenderer::projectionOrthographique(const vector<Vector3f>& points3D, RenderWindow& window) 
{
    vector<Vector2f> points2D(points3D.size());
    for (size_t i = 0; i < points3D.size(); i++) 
        points2D[i] = Vector2f(points3D[i].x, points3D[i].y);
    return points2D;
}

void CubeRenderer::pivot(vector<Vector3f>& vecteur, Vector2f& angle, const Vector3f axe) 
{
    float cosY = cos(angle.y * M_PI / 180), sinY = sin(angle.y * M_PI / 180);
    float cosX = cos(angle.x * M_PI / 180), sinX = sin(angle.x * M_PI / 180);

    // Créer les matrices de rotation
    RotationMatrixX rotX(cosX, sinX);
    RotationMatrixY rotY(cosY, sinY);

    for (auto& point : vecteur)
    {
        point -= rotationCentre;

        if(axe.y != 0)
            rotY.calculate(point);

        if(axe.x != 0)
            rotX.calculate(point);

        point += rotationCentre;
    }
}

void CubeRenderer::dessinerVecteur(vector<Vector2f>& matrixCube, RenderWindow& window)
{
    sf::Transform translation;
    translation.translate(-300, 30);
    
    for (size_t i = 0; i < matrixCube.size() - 1; i++) 
    {
        sf::Vertex line[] = 
        {    
            sf::Vertex(matrixCube[i], sf::Color::Red),
            sf::Vertex(matrixCube[i + 1], sf::Color::Red)
        };
        window.draw(line, 2, sf::Lines);
    }
}

void CubeRenderer::tableauPivot(vector<vector<Vector3f>>& tableauDeMatrixCube, 
                                Vector3f pivotPointAxe, 
                                Vector2f& angle, 
                                Vector3f& DirectionPivot)
{
    if(pivotPointAxe.x == 1) angle.x++;
    else if(pivotPointAxe.x == -1) angle.x--;
    else if(pivotPointAxe.y == 1) angle.y++;
    else if(pivotPointAxe.y == -1) angle.y--;
    
    for(size_t i = 0; i < tableauDeMatrixCube.size(); i++)
        pivot(tableauDeMatrixCube[i], angle, DirectionPivot);
}

void CubeRenderer::TableauCube(Vector3f initCoord, 
                               vector<vector<Vector3f>>& tableauDeMatrixCube, 
                               int taille, 
                               int nombreCube)
{
    for(int i = 0; i < nombreCube; i++)
    {
        initCoord.x += taille;
        tableauDeMatrixCube[i].resize(CUBE_VERTICES);
        genererCube(tableauDeMatrixCube[i], initCoord, taille);
    }  
}

void CubeRenderer::setRotationCentre(const Vector3f& centre)
{
    rotationCentre = centre;
}

