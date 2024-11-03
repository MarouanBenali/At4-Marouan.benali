#include <iostream>
using namespace std;

class Personne {
protected:
    string nom, prenom, date_naissance;

public:
    Personne(string n, string p, string dn) : nom(n), prenom(p), date_naissance(dn) {}

    void Afficher() const {
        cout << "\nNom: " << nom << "\nPrénom: " << prenom << "\nDate de naissance: " << date_naissance << endl;
    }
};

class Employe : public Personne {
private:
    double salaire;

public:
    Employe(string n, string p, string dn, double s) : Personne(n, p, dn), salaire(s) {}

    void Afficher() const { // Redéfinition de la méthode Afficher
        Personne::Afficher();
        cout << "Salaire: " << salaire << "DH" << endl;
    }
};

class Chef : public Employe {
private:
    string service;

public:
    Chef(string n, string p, string dn, double s, string serv) : Employe(n, p, dn, s), service(serv) {}

    void Afficher() const { // Redéfinition de la méthode Afficher
        Employe::Afficher();
        cout << "Service: " << service << endl;
    }
};

class Directeur : public Chef {
private:
    string societe;

public:
    Directeur(string n, string p, string dn, double s, string serv, string soc) : Chef(n, p, dn, s, serv), societe(soc) {}

    void Afficher() const { // Redéfinition de la méthode Afficher
        Chef::Afficher();
        cout << "Société: " << societe << endl;
    }
};

int main() {
    Personne p("BENALI", "Marouan", "13/10/1999");
    Employe e("MAHIR", "Fatima", "12/03/1975", 3000);
    Chef c("BENARFA", "khalid", "15/07/1990", 4000, "Informatique");
    Directeur d("MOUTAWAKIL", "Mariam", "30/10/2000", 5000, "RH", "Cablirias");

    p.Afficher();
    cout << "--------------------" << endl;
    e.Afficher();
    cout << "--------------------" << endl;
    c.Afficher();
    cout << "--------------------" << endl;
    d.Afficher();

    return 0;
}
