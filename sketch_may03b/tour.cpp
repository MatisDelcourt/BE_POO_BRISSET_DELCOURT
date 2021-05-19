#include <iostream>
#include <string>
#include "tour.h"
using namespace std;

//Classe qui gère le tour de chaque joueur

//Constructeur avec toutes les variables initialisées
tour::tour() {
    this->de1 = 0;
    this->de2 = 0;
    this->somme = 0;
    this->attente = false;
}

//Fonction mettant à jour le tour du joueur (score du dé 1, score du dé 2 et somme des dés)
void tour::majtour(int lancer) {
    if (this->attente == false) {
        this->de1 = lancer;
        this->attente = true;
    }
    else {
        this->de2 = lancer;
        this->somme = this->de2 + this->de1;
        this->attente = false;
    }
}
