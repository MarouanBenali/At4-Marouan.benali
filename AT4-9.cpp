#include <iostream>

class Element {
public:
    int valeur; // Valeur de l'élément
    Element* suivant; // Pointeur vers l'élément suivant

    // Constructeur
    Element(int val) : valeur(val), suivant(nullptr) {}
};

class Liste {
private:
    Element* tete; // Pointeur vers le premier élément de la liste

public:
    // Constructeur
    Liste() : tete(nullptr) {}

    // Destructeur pour libérer la mémoire
    ~Liste() {
        while (tete != nullptr) {
            supprimer(); // Supprime tous les éléments
        }
    }

    // Méthode pour ajouter un élément au début de la liste
    void ajouter(int val) {
        Element* nouvelElement = new Element(val); // Crée un nouvel élément
        nouvelElement->suivant = tete; // Lien vers l'ancien premier élément
        tete = nouvelElement; // Met à jour le pointeur tête
    }

    // Méthode pour supprimer le premier élément de la liste
    void supprimer() {
        if (tete != nullptr) {
            Element* temp = tete; // Garde l'élément à supprimer
            tete = tete->suivant; // Met à jour la tête
            delete temp; // Libère la mémoire
        }
    }

    // Méthode pour afficher la liste
    void afficher() const {
        Element* courant = tete; // Pointeur pour parcourir la liste
        while (courant != nullptr) {
            std::cout << courant->valeur << " "; // Affiche la valeur de l'élément
            courant = courant->suivant; // Passe à l'élément suivant
        }
        std::cout << std::endl;
    }
};
int main() {
    Liste maListe; // Crée une instance de Liste

    // Ajoute des éléments à la liste
    maListe.ajouter(10);
    maListe.ajouter(20);
    maListe.ajouter(30);

    std::cout << "Liste après ajout : ";
    maListe.afficher(); // Affiche la liste

    // Supprime le premier élément
    maListe.supprimer();
    std::cout << "Liste après suppression : ";
    maListe.afficher(); // Affiche la liste

    return 0;
}
