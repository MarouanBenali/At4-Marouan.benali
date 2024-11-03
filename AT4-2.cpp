#include <iostream>
#include <string>
using namespace std;

// Classe mère Animal
class Animal {
protected:
    string nom;
    int age;

public:
    // Méthode pour définir le nom et l'âge de l'animal
    void set_value(string n, int a) {
        nom = n;
        age = a;
    }
};

// Sous-classe Zebra
class Zebra : public Animal {
public:
    // Affiche les informations de la Zebra
    void afficher_info() {
        cout << "Nom : " << nom << ", Age : " << age << " ans" << endl;
        cout << "Informations supplémentaires : La zèbre vient d'Afrique." << endl;
    }
};

// Sous-classe Dolphin
class Dolphin : public Animal {
public:
    // Affiche les informations du Dauphin
    void afficher_info() {
        cout << "Nom : " << nom << ", Age : " << age << " ans" << endl;
        cout << "Informations supplémentaires : Le dauphin habite dans les océans." << endl;
    }
};

int main() {
    // Création des instances de Zebra et Dolphin
    Zebra zebra;
    Dolphin dolphin;

    // Initialisation des valeurs pour chaque animal
    zebra.set_value("Marty", 4);
    dolphin.set_value("Flipper", 7);

    // Affichage des informations pour chaque animal
    cout << "Informations pour la Zebra:" << endl;
    zebra.afficher_info();

    cout << "\nInformations pour le Dolphin:" << endl;
    dolphin.afficher_info();

    return 0;
}
