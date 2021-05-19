#include <iostream>
#include <string>
#include "joueur.h"
using namespace std;

//Classe pour créer les joueurs

//Constructeur qui crée un joueur avec un numéro, un nom, et un numéro de role
joueur::joueur(int nojoueur, string nomjoueur, int nrole) {
	this->no = nojoueur;
	this->nom = nomjoueur;
	this->role = nrole;
}

//Constructeur de copie
joueur::joueur(const joueur & copied_joueur) {
	this->no = copied_joueur.no;
	this->nom = copied_joueur.nom;
	this->role = copied_joueur.role;

}
