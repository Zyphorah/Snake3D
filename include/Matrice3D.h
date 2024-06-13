#include "../include/main.h"

struct RepereLocal 
{
    Vector3f i; // Axe X local
    Vector3f j; // Axe Y local
    Vector3f k; // Axe Z local
};

void initialiserRepereLocal(RepereLocal& repere, const Vector3f& initCoord); 
void genererCube(vector<Vector3f>& matrixCube,Vector3f& initCoord,int taille);
vector<Vector2f> projectionOrthographique(const vector<Vector3f>& points3D, RenderWindow& window);
void pivot(vector<Vector3f>& vecteur, float angle, const Vector3f axe);
void dessinerVecteur(vector<Vector2f>&matrixCube,RenderWindow& window);  
void tableauPivot(vector<vector<Vector3f>>& tableauDeMatrixCube,Vector3f pivotPointAxe);
void TableauCube(Vector3f initCoord,vector<vector<Vector3f>>& tableauDeMatrixCube,int taille,int nombreCube);