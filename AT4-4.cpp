#include <iostream>
#include <cmath>
using namespace std;

class Vecteur3D {
private:
    float x, y, z;

public:
    // Constructeur avec des valeurs par défaut (0,0,0)
    Vecteur3D(float px = 0, float py = 0, float pz = 0) : x(px), y(py), z(pz) {}

    // Fonction d'affichage des composantes du vecteur
    void afficher() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    // Fonction pour obtenir la somme de deux vecteurs
    Vecteur3D somme(Vecteur3D &v) const {
        return Vecteur3D(x + v.x, y + v.y, z + v.z);
    }

    // Fonction pour obtenir le produit scalaire de deux vecteurs
    float produitScalaire(Vecteur3D &v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    // Fonction coincide pour vérifier si deux vecteurs ont les mêmes composantes
    bool coincide(Vecteur3D &v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    // Fonction pour calculer la norme du vecteur
    float norme() const {
        return sqrt(x*x + y*y + z*z);
    }

    // 1. Retour de normax par valeur
    Vecteur3D normaxParValeur(const Vecteur3D &v) const {
        return (this->norme() > v.norme()) ? *this : v;
    }

    // 2. Retour de normax par adresse
    const Vecteur3D* normaxParAdresse(const Vecteur3D *v) const {
        return (this->norme() > v->norme()) ? this : v;
    }

    // 3. Retour de normax par référence
    const Vecteur3D& normaxParReference(const Vecteur3D &v) const {
        return (this->norme() > v.norme()) ? *this : v;
    }
};

int main() {
    Vecteur3D v1(1, 2, 3);
    Vecteur3D v2(4, 5, 6);

    cout << "Vecteur 1: ";
    v1.afficher();
    cout << "Vecteur 2: ";
    v2.afficher();

    cout << "\nSomme des vecteurs: ";
    Vecteur3D vSomme = v1.somme(v2);
    vSomme.afficher();

    cout << "\nProduit scalaire des vecteurs: " << v1.produitScalaire(v2) << endl;

    cout << "\nLes vecteurs sont ";
    cout << (v1.coincide(v2) ? "identiques" : "différents") << endl;

    cout << "\nNorme du vecteur 1: " << v1.norme() << endl;
    cout << "Norme du vecteur 2: " << v2.norme() << endl;

    cout << "\nVecteur avec la norme maximale (par valeur): ";
    Vecteur3D vNormax = v1.normaxParValeur(v2);
    vNormax.afficher();

    cout << "Vecteur avec la norme maximale (par adresse): ";
    const Vecteur3D *vNormaxPtr = v1.normaxParAdresse(&v2);
    vNormaxPtr->afficher();

    cout << "Vecteur avec la norme maximale (par référence): ";
    const Vecteur3D &vNormaxRef = v1.normaxParReference(v2);
    vNormaxRef.afficher();

    return 0;
}
