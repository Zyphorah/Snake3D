# Jeu Snake 3D en C++ avec SFML
!vidéo.mp4

## Description
Ce projet est un jeu Snake 3D réalisé en C++ en utilisant la bibliothèque graphique SFML. L'objectif était de créer un rendu 3D sans utiliser de bibliothèque 3D ou de moteur de jeu, mais en appliquant uniquement l'algèbre linéaire pour développer le jeu.

## Fonctionnalités
- Rendu 3D de la grille de jeu et du serpent.
- Déplacement et téléportation du serpent dans un espace 3D.
- Gestion des collisions et de la croissance du serpent.
- Rotation et projection orthographique pour visualiser le jeu en 3D.

## Dépendances
- SFML (Simple and Fast Multimedia Library)

## Installation sur Debian

1. Mettez à jour la liste des paquets :

sudo apt update

2. Installez la bibliothèque SFML :

sudo apt install libsfml-dev

3. Clonez le dépôt du projet :

git clone https://github.com/Zyphorah/Snake3D.git

4. Naviguez dans le répertoire du projet :

cd Snake3D

5. Compilez le projet avec g++;

 g++ src/main.cpp src/Matrice3D.cpp src/keycontrole.cpp -o Snake3D -lsfml-graphics -lsfml-window -lsfml-system

 ## Utilisez Debian pour compiler un exécutable window 10 

 g++ -I"sfml/include" src/main.cpp src/Matrice3D.cpp src/keycontrole.cpp -o Snake3D.exe -L"sfml/lib" -lsfml-graphics -lsfml-window -lsfml-system

6. Exécutez le jeu :

./snake3D

### Contrôle du Serpent
- **A** : Déplacement du serpent vers la droite.
- **D** : Déplacement du serpent vers la gauche.
- **W** : Déplacement du serpent vers l'avant (axe vertical).
- **S** : Déplacement du serpent vers l'arrière (sens inverse de W).
- **Q** : Descente du serpent (réduction de l'altitude).
- **E** : Montée du serpent (augmentation de l'altitude).

Le serpent grandit d'un cube après avoir parcouru quatre cases. Faites attention à ne pas heurter le corps du serpent pendant que vous le déplacez.

### Contrôle de la Caméra
- Utilisez les **touches directionnelles** pour ajuster l'angle de vue de la caméra.
