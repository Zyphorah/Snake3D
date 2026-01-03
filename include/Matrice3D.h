#ifndef MATRICE3D_H
#define MATRICE3D_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

using namespace sf;
using namespace std;

void genererCube(vector<Vector3f>& matrixCube, Vector3f& initCoord, int taille);
vector<Vector2f> projectionOrthographique(const vector<Vector3f>& points3D, RenderWindow& window);
void pivot(vector<Vector3f>& vecteur, Vector2f& angle, const Vector3f axe);
void dessinerVecteur(vector<Vector2f>& matrixCube, RenderWindow& window);  
void tableauPivot(vector<vector<Vector3f>>& tableauDeMatrixCube, Vector3f pivotPointAxe, Vector2f& angle, Vector3f& DirectionPivot);
void TableauCube(Vector3f initCoord, vector<vector<Vector3f>>& tableauDeMatrixCube, int taille, int nombreCube);

#endif
