#include <iostream>
#include "Point.h"

int main() {
    // Création d'un point avec des coordonnées initiales
    Point p(2.0f, 3.0f);

    // Affichage des coordonnées initiales
    p.affiche();

    // Déplacement du point
    p.deplace(1.5f, -1.0f);

    // Affichage des coordonnées après déplacement
    p.affiche();

    return 0;
}
