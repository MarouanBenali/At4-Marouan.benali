#include <iostream>
#include "Point.h"

// Constructeur
Point::Point(float xCoord, float yCoord) : x(xCoord), y(yCoord) {}

// Méthode pour déplacer le point
void Point::deplace(float dx, float dy) {
    x += dx; // Translation sur l'axe x
    y += dy; // Translation sur l'axe y
}

// Méthode pour afficher les coordonnées
void Point::affiche() const {
    std::cout << "Coordonnées du point : (" << x << ", " << y << ")" << std::endl;
}
