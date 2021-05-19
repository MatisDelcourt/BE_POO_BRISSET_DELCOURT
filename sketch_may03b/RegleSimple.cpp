#include <iostream>
#include <string>
#include<vector>
#include <sstream>
#include "RegleSimple.h"
using namespace std;

//Classe pour les règles simples

//Constructeur
RegleSimple::RegleSimple(int id, string nom, int de1, int de2, int somme, int actif, int gorgees) {
    this->idregle = id;
    this->nomregle = nom;
    this->de1regle = de1;
    this->de2regle = de2;
    this->sommeregle = somme;
    this->actifregle = actif;
    this->nbgorgees = gorgees;
}

//Constructeur de copie
RegleSimple::RegleSimple(const RegleSimple& copied_RegleSimple) {
    this->idregle = copied_RegleSimple.idregle;
    this->nomregle = copied_RegleSimple.nomregle;
    this->de1regle = copied_RegleSimple.de1regle;
    this->de2regle = copied_RegleSimple.de2regle;
    this->sommeregle = copied_RegleSimple.sommeregle;
    this->actifregle = copied_RegleSimple.actifregle;
    this->nbgorgees = copied_RegleSimple.nbgorgees;

}

//Renvoie 0 car pas de rôle
int RegleSimple::getrole() {
    return 0;
}

//Renvoie faux car pas une règle récurrente
bool RegleSimple::getrecurrent() {
    return false;
}

//Renvoie 0 car pas récurrent
int RegleSimple::getderec() {
    return 0;
}

//Renvoie 0 car pas récurrent
int RegleSimple::getsommerec() {
    return 0;
}

bool RegleSimple::getactif() {
    return false;
}

void RegleSimple::giveactif() {
}

//fonction renvoyant la chaîne de caractères de la règle
string RegleSimple::afficherregle(vector<joueur> tabjoueur, int nojoueur, vector<RegleSimple*> tabregles, int noregle) {
  stringstream ss;
  ss << tabregles[noregle]->nbgorgees;
  ss >> chainestr;
  chainestr = string(tabregles[noregle]->nomregle.c_str())+string(" boit ")+chainestr+string(" gorgees ");
  return chainestr;
}

string RegleSimple::afficherreglerec(vector<joueur> tabjoueur, int nojoueur, vector<RegleSimple*> tabregles, int noregle) {
}
