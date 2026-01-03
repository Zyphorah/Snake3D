#ifndef CUBE_RENDERER_H
#define CUBE_RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

using namespace sf;
using namespace std;

class CubeRenderer
{
    private:
        Vector3f rotationCentre;
        static const int CUBE_VERTICES = 17;
        

        void genererSommets(vector<Vector3f>& corners, const Vector3f& initCoord, int taille);
      
        vector<int> obtenirCheminTracé();
        
        void construireBuffer(vector<Vector3f>& matrixCube, const vector<Vector3f>& corners, const vector<int>& path);

    public:
        CubeRenderer(const Vector3f& centre = Vector3f(500, 300, 100));
        ~CubeRenderer() = default;
        
        void genererCube(vector<Vector3f>& matrixCube, Vector3f& initCoord, int taille);
        
        vector<Vector2f> projectionOrthographique(const vector<Vector3f>& points3D, RenderWindow& window);
        
        void pivot(vector<Vector3f>& vecteur, Vector2f& angle, const Vector3f axe);
        
        void dessinerVecteur(vector<Vector2f>& matrixCube, RenderWindow& window);
        
        void tableauPivot(vector<vector<Vector3f>>& tableauDeMatrixCube, 
                        Vector3f pivotPointAxe, 
                        Vector2f& angle, 
                        Vector3f& DirectionPivot);
        
        void TableauCube(Vector3f initCoord, 
                        vector<vector<Vector3f>>& tableauDeMatrixCube, 
                        int taille, 
                        int nombreCube);
        
        void setRotationCentre(const Vector3f& centre);
};

#endif
