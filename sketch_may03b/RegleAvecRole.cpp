#include <iostream>
#include <string>
#include<vector>
#include "RegleAvecRole.h"
using namespace std;

//Classe pour les règles définissant un rôle simple

//Constructeur 
RegleAvecRole::RegleAvecRole(int id, string nom, int de1, int de2, int somme, int actif, int gorgees, int role): RegleSimple(id, nom, de1, de2, somme, actif, gorgees) {
	this->idrole = role;
}

//Constructeur de copie
RegleAvecRole::RegleAvecRole(const RegleAvecRole & copied_RegleAvecRole): RegleSimple(RegleSimple(copied_RegleAvecRole.idregle, copied_RegleAvecRole.nomregle, copied_RegleAvecRole.de1regle, copied_RegleAvecRole.de2regle, copied_RegleAvecRole.sommeregle, copied_RegleAvecRole.actifregle, copied_RegleAvecRole.nbgorgees)) {
	this->idrole= copied_RegleAvecRole.idrole;
}

//fonction renvoyant l'id du rôle
int RegleAvecRole::getrole() {
	return this->idrole;
}

//fonction renvoyant la chaîne de caractères de la nouvelle règle avec un rôle (ex : Martin devient le maitre des gorgées)
string RegleAvecRole::afficherregle(vector<joueur> tabjoueur, int nojoueur, vector<RegleSimple*> tabregles, int noregle) {
  chainestr3 = string(tabjoueur[nojoueur].nom.c_str())+string(" devient ")+string(tabregles[noregle]->nomregle.c_str());
  return chainestr3;
}
