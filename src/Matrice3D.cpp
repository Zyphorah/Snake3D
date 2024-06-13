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
        matrixCube[i].z = taille;
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

//Permet de faire une rotation sur un point x, y ou z, z est la profondeur
void pivot(vector<Vector3f>& vecteur, float angle, const Vector3f axe) 
{
    Vector3f centre{500, 300, 100};
    float rad = angle * M_PI / 180; // Conversion de degrés en radians
     
    for (int i = 0; i < vecteur.size(); i++)
    {
        // Translation pour placer le centre de rotation à l'origine
        vecteur[i].x -= centre.x;
        vecteur[i].y -= centre.y;
        vecteur[i].z -= centre.z;

        // Rotation autour de l'axe Y
        if(axe.y == 1)
        {
            float x = vecteur[i].x * cos(rad) - vecteur[i].z * sin(rad);
            float z = vecteur[i].x * sin(rad) + vecteur[i].z * cos(rad);
            vecteur[i].x = x;
            vecteur[i].z = z;
        }
        
        if(axe.y == -1)     
        {
            float x = vecteur[i].x * cos(rad) + vecteur[i].z * sin(rad);
            float z = vecteur[i].x * -sin(rad) + vecteur[i].z * cos(rad);
            vecteur[i].x = x;
            vecteur[i].z = z;
        }



        // Rotation autour de l'axe X
        if(axe.x == 1)
        {
            float y = vecteur[i].y * cos(rad) - vecteur[i].z * sin(rad);
            float z = vecteur[i].y * sin(rad) + vecteur[i].z * cos(rad);
            vecteur[i].y = y;
            vecteur[i].z = z;
        }
        if(axe.x == -1)
        {
            float y = vecteur[i].y * cos(rad) + vecteur[i].z * sin(rad);
            float z = -vecteur[i].y * sin(rad) + vecteur[i].z * cos(rad);
            vecteur[i].y = y;
            vecteur[i].z = z;
        }



        // Rotation autour de l'axe Z
        if(axe.z == 1)
        {
            float x = vecteur[i].x * cos(rad) - vecteur[i].y * sin(rad);
            float y = vecteur[i].x * sin(rad) + vecteur[i].y * cos(rad);
            vecteur[i].x = x;
            vecteur[i].y = y;
        }

        // Retranslation pour remettre le centre de rotation à sa position initiale
        vecteur[i].x += centre.x;
        vecteur[i].y += centre.y;
        vecteur[i].z += centre.z;
    }
}

// Dessiner les vecteurs du cub
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

void tableauPivot(vector<vector<Vector3f>>& tableauDeMatrixCube,Vector3f pivotPointAxe)
{
    for(int i =0 ; i < tableauDeMatrixCube.size();i++)
    {
        pivot(tableauDeMatrixCube[i],1,pivotPointAxe);
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