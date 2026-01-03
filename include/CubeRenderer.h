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
        

        void generateVertices(vector<Vector3f>& corners, const Vector3f& initCoord, int size);
      
        vector<int> getDrawingPath();
        
        void buildBuffer(vector<Vector3f>& matrixCube, const vector<Vector3f>& corners, const vector<int>& path);

    public:
        CubeRenderer(const Vector3f& centre = Vector3f(500, 300, 100));
        ~CubeRenderer() = default;
        
        void generateCube(vector<Vector3f>& matrixCube, Vector3f& initCoord, int size);
        
        vector<Vector2f> orthographicProjection(const vector<Vector3f>& points3D, RenderWindow& window);
        
        void rotate(vector<Vector3f>& vecteur, Vector2f& angle, const Vector3f axe);
        
        void drawLine(vector<Vector2f>& matrixCube, RenderWindow& window);
        
        void rotateMatrix(vector<vector<Vector3f>>& tableauDeMatrixCube, 
                        Vector3f pivotPointAxe, 
                        Vector2f& angle, 
                        Vector3f& DirectionPivot);
        
        void generateCubeMatrix(Vector3f initCoord, 
                        vector<vector<Vector3f>>& tableauDeMatrixCube, 
                        int size, 
                        int numberOfCubes);
        
        void setRotationCentre(const Vector3f& centre);
};

#endif
