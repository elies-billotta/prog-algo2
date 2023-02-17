#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
};

void initialise(Liste* liste)
{
    liste->premier = NULL;
}

bool est_vide(const Liste* liste)
{
    return liste->premier == NULL;
}

void ajoute(Liste* liste, int valeur)
{
    if (liste->premier == NULL)
    {
        liste->premier = new Noeud;
        liste->premier->donnee = valeur;
        liste->premier->suivant = NULL;
    }
    else {
        Noeud *current = liste->premier;
        while (current->suivant != NULL)
        {
            current = current->suivant;
        }
        current->suivant = new Noeud;
        current->suivant->donnee = valeur;
        current->suivant->suivant = NULL;
    }
}

void affiche(const Liste* liste)
{
    Noeud *current = liste->premier;
    while (current->suivant != NULL)
    {
        cout << current->donnee << endl;
        current = current->suivant;
    }
}

int recupere(const Liste* liste, int n)
{
    Noeud *current = liste->premier;
    int i = 0;
    while (current->suivant != NULL)
    {
        if (i == n)
        {
            return current->donnee;
        }
        current = current->suivant;
        i++;
    }
    return 0;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud *current = liste->premier;
    int i = 0;
    while (current->suivant != NULL)
    {
        if (current->donnee == valeur)
        {
            return i;
        }
        current = current->suivant;
        i++;
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud *current = liste->premier;
    int i = 0;
    while (current->suivant != NULL)
    {
        if (i == n)
        {
            current->donnee = valeur;
        }
        current = current->suivant;
        i++;
    }
}

//--------------------------------------------------- Tableau Dynamique ---------------------------------------------------

struct DynaTableau{
    int* donnees;
    // your code
};

void ajoute(DynaTableau* tableau, int valeur)
{
    
}


void initialise(DynaTableau* tableau, int capacite)
{

}

bool est_vide(const DynaTableau* liste)
{
    return false;
}

void affiche(const DynaTableau* tableau)
{

}

int recupere(const DynaTableau* tableau, int n)
{
    return 0;
}

int cherche(const DynaTableau* tableau, int valeur)
{
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{

}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{

}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    return 0;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{

}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    return 0;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
