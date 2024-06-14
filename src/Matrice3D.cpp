#include "../include/Matrice3D.h"

void genererCube(vector<Vector3f>& matrixCube,Vector3f& initCoord,int taille)
{
     /* 
        {100, 100, 0}, // Point A, c'est le point d'orrigine
        {300, 100, 0}, // Point B
        {300, 300, 0}, // Point C
        {100, 300, 0}, // Point D
        {100, 100, 0}, // Retour au Point A pour fermer le carré
    */
   // Initialisation du premier point A du cube
    matrixCube[0] = initCoord;
    
    //Modification des points
        //Point B = 1 
        matrixCube[1]=matrixCube[0];
        matrixCube[1].x +=taille;
        
        // Pour le points C 
        matrixCube[2]=matrixCube[1];
        matrixCube[2].y += taille/2;    
        //Point D = 3 
        matrixCube[3]=matrixCube[2];
        matrixCube[3].x -=taille;
        
    // Connexion du point D au point A pour fermer la face
    matrixCube[4] = initCoord;

    //Génération du carré superposé. Reprendre uniquement les points de l'autre cube pour ajouter la variable de profondeur z.
    for(int i =5; i<=9;i++)
    {
        //Récupération du premier point
        matrixCube[i] = matrixCube[i-5];
        matrixCube[i].z += taille;
    }
    //Génération des points relier au point A,B,C,D
    //Exemple 
    /* {100, 100, 0}, // Point A
        {300, 100, 0}, // Point B
        {300, 100, 100}, // Point F
        {300, 300, 100}, // Point G
        {300, 300, 0}, // Point C
        {100, 300, 0}, // Point D   
        {100, 300, 100}, // Point H, superposé au Point D 
    */
   matrixCube[10] = matrixCube[0];// Point A
   matrixCube[11] = matrixCube[1]; // Point B
   matrixCube[12] = matrixCube[6]; // Point F
   matrixCube[13] = matrixCube[7]; // Point G
   matrixCube[14] = matrixCube[2]; // Point C
   matrixCube[15] = matrixCube[3]; // Point D
   matrixCube[16] = matrixCube[8]; // Point H
}

//ProjectionOrthographique transformer la 3D vers de la 2D
vector<Vector2f> projectionOrthographique(const vector<Vector3f>& points3D, RenderWindow& window) 
{
    vector<Vector2f> points2D(points3D.size());
    for (int i = 0; i < points3D.size(); i++) 
    {
        float x = points3D[i].x;
        float y = points3D[i].y;
        points2D[i] = Vector2f(x, y);
    }
    return points2D;
}

//Permet de faire une rotation sur un point x, y ou z, z est la profondeurvoid pivot(vector<Vector3f>& vecteur, Vector2f& angle, const Vector3f axe) 
void pivot(vector<Vector3f>& vecteur, Vector2f& angle, const Vector3f axe) 
{
    Vector3f centre{500, 300, 100};
    float radX = angle.x * M_PI / 180; // Conversion de degrés en radians
    float radY = angle.y * M_PI / 180;

    // Précalcul des sinus et cosinus
    float cosY = cos(radY), sinY = sin(radY);
    float cosX = cos(radX), sinX = sin(radX);

    for (auto& point : vecteur)
    {
        // Translation pour placer le centre de rotation à l'origine
        point.x -= centre.x;
        point.y -= centre.y;
        point.z -= centre.z;

        // Rotation autour de l'axe Y
        if(axe.y != 0)
        {
            float x = point.x * cosY + point.z * sinY;
            float z = -point.x * sinY + point.z * cosY;
            point.x = x;
            point.z = z;
        }

        // Rotation autour de l'axe X
        if(axe.x != 0)
        {
            float y = point.y * cosX + point.z * sinX;
            float z = -point.y * sinX + point.z * cosX;
            point.y = y;
            point.z = z;
        }

        // Retranslation pour remettre le centre de rotation à sa position initiale
        point.x += centre.x;
        point.y += centre.y;
        point.z += centre.z;
    }
}


// Dessiner les vecteurs du cube
void dessinerVecteur(vector<Vector2f>&matrixCube,RenderWindow& window)
{
    for (int i = 0; i < matrixCube.size() - 1; i++) 
        {
            sf::Transform translation;
            translation.translate(-300, 30);
            translation.transformPoint(matrixCube[i]);
            sf::Vertex line[] = 
            {    
                sf::Vertex(matrixCube[i], sf::Color::Red),
                sf::Vertex(matrixCube[i + 1], sf::Color::Red)
            };

            window.draw(line, 2, sf::Lines);
        }
}

//Pivote le corp du snake
void tableauPivot(vector<vector<Vector3f>>& tableauDeMatrixCube,Vector3f pivotPointAxe,Vector2f& angle,Vector3f& DirectionPivot)
{
    //Condition pour gérer l'angle
    if(pivotPointAxe.x ==1)
    {
        angle.x++;
    }
    else if (pivotPointAxe.x == -1)
    {
       angle.x--;
    }
    else if(pivotPointAxe.y ==1)
    {
        angle.y++;
    }
    else if (pivotPointAxe.y == -1)
    {
       angle.y--;
    }
    
    for(int i =0 ; i < tableauDeMatrixCube.size();i++)
    {
        pivot(tableauDeMatrixCube[i],angle,DirectionPivot);
    }
}

void TableauCube(Vector3f initCoord,vector<vector<Vector3f>>& tableauDeMatrixCube,int taille,int nombreCube)
{
    for(int i =0;i<nombreCube;i++)
    {
        initCoord.x+=taille;
        tableauDeMatrixCube[i].resize(17);
        genererCube(tableauDeMatrixCube[i],initCoord,taille);
    }  
}