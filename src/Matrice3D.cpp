#include "../include/Matrice3D.h"


// Fonction utiliser pour faire un repaire de coordonné x,y,z, elle serviras pour la rotation qui est utiliser comme camera
void initialiserRepereLocal(RepereLocal& repere, const Vector3f& initCoord) 
{
    repere.i = Vector3f(1, 0, 0); // Axe X local
    repere.j = Vector3f(0, 1, 0); // Axe Y local
    repere.k = Vector3f(0, 0, 1); // Axe Z local
}

//Translation locale sur les vector x,y,z
void translationLocale(vector<Vector3f>& points, const RepereLocal& repere, const Vector3f& translation) 
{
    for (auto& point : points) 
    {
        point += repere.i * translation.x + repere.j * translation.y + repere.k * translation.z;
    }
}

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
void pivot(vector<Vector3f>& vecteur, float angle,Vector3f axe, RepereLocal& repere) 
{
    Vector3f centre{500, 300, 100};
    float rad = angle * M_PI / 180; // Conversion de degrés en radians

    // Mise à jour des axes du repère local en fonction de la rotation
    if(axe.y == 1)
    {
        repere.i = Vector3f(cos(rad), 0, sin(rad));
        repere.k = Vector3f(-sin(rad), 0, cos(rad));
    }
    else if(axe.y == -1)
    {
        repere.i = Vector3f(cos(rad), 0, -sin(rad));
        repere.k = Vector3f(sin(rad), 0, cos(rad));
    }

    if(axe.x == 1)
    {
        repere.j = Vector3f(0, cos(rad), -sin(rad));
        repere.k = Vector3f(0, sin(rad), cos(rad));
    }
    else if(axe.x == -1)
    {
        repere.j = Vector3f(0, cos(rad), sin(rad));
        repere.k = Vector3f(0, -sin(rad), cos(rad));
    }

    if(axe.z == 1)
    {
        repere.i = Vector3f(cos(rad), -sin(rad), 0);
        repere.j = Vector3f(sin(rad), cos(rad), 0);
    }

    for (int i = 0; i < vecteur.size(); i++)
    {
        // Translation pour placer le centre de rotation à l'origine
        vecteur[i].x -= centre.x;
        vecteur[i].y -= centre.y;
        vecteur[i].z -= centre.z;

        // Appliquer la rotation en utilisant les axes du repère local
        Vector3f pointRotated = repere.i * vecteur[i].x + repere.j * vecteur[i].y + repere.k * vecteur[i].z;

        // Retranslation pour remettre le centre de rotation à sa position initiale
        vecteur[i].x = pointRotated.x + centre.x;
        vecteur[i].y = pointRotated.y + centre.y;
        vecteur[i].z = pointRotated.z + centre.z;
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

void tableauPivot(vector<vector<Vector3f>>& tableauDeMatrixCube,Vector3f pivotPointAxe,RepereLocal& repere)
{
    for(int i =0 ; i < tableauDeMatrixCube.size();i++)
    {
        pivot(tableauDeMatrixCube[i],1,pivotPointAxe,repere);
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