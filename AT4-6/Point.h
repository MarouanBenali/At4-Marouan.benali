#ifndef POINT_H
#define POINT_H

class Point {
private:
    float x, y; // Coordonnée x et y

public:
    Point(float xCoord, float yCoord);// Constructeur
    void deplace(float dx, float dy);// Méthode pour déplacer le point
    void affiche() const;// Méthode pour afficher les coordonnées
};

#endif // POINT_H
