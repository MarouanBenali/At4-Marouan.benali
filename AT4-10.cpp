#include <iostream>
#include <string>

int main() {
    // Chaîne de caractères contenant la date et l'heure
    std::string dateHeure = "010920091123"; // Exemple de date et heure

    // Vérification de la longueur de la chaîne
    if (dateHeure.length() != 12) {
        std::cerr << "La chaîne doit avoir exactement 12 caractères." << std::endl;
        return 1;
    }

    // Extraction des différents champs
    std::string jour = dateHeure.substr(0, 2);   // JJ
    std::string mois = dateHeure.substr(2, 2);   // MM
    std::string annee = dateHeure.substr(4, 4);  // AAAA
    std::string heure = dateHeure.substr(8, 2);  // HH
    std::string minutes = dateHeure.substr(10, 2); // NN

    // Affichage des résultats
    std::cout << "Date : " << jour << "/" << mois << "/" << annee << std::endl;
    std::cout << "Heure : " << heure << ":" << minutes << std::endl;

    return 0;
}
