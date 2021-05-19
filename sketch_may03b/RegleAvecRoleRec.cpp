#include <iostream>
#include <string>
#include<vector>
#include <sstream>
#include "RegleAvecRoleRec.h"
#include "joueur.h"
using namespace std;

//Classe pour les règles définissant un rôle récurrent (qui revient pour un score de dés particulier)

//Constructeur
RegleAvecRoleRec::RegleAvecRoleRec(int id, string nom, int de1, int de2, int somme, int actif, int gorgees, int role, bool rec, int der, int sommer): RegleAvecRole(id, nom, de1, de2, somme, actif, gorgees, role) {
	this->derec = der;
	this->recurrent = rec;
	this->sommerec = sommer;
	this->actifrec = false;
}

//Constructeur de copie
RegleAvecRoleRec::RegleAvecRoleRec(const RegleAvecRoleRec& copied_RegleAvecRoleRec) : RegleAvecRole(RegleAvecRole(copied_RegleAvecRoleRec.idregle, copied_RegleAvecRoleRec.nomregle, copied_RegleAvecRoleRec.de1regle, copied_RegleAvecRoleRec.de2regle, copied_RegleAvecRoleRec.sommeregle, copied_RegleAvecRoleRec.actifregle, copied_RegleAvecRoleRec.nbgorgees, copied_RegleAvecRoleRec.idrole)) {
	this->derec= copied_RegleAvecRoleRec.derec;
	this->recurrent = copied_RegleAvecRoleRec.recurrent;
	this->sommerec = copied_RegleAvecRoleRec.sommerec;
}

bool RegleAvecRoleRec::getrecurrent() {
	return this->recurrent;
}

//Renvoie la valeur du dé associée au rôle
int RegleAvecRoleRec::getderec() {
	return this->derec;
}

//Renvoie la valeur de la somme des dés associée au rôle
int RegleAvecRoleRec::getsommerec() {
	return this->sommerec;
}

//Renvoie l'état du rôle récurrent
bool RegleAvecRoleRec::getactif() {
	return this->actifrec;
}

//Rend actif un rôle récurrent
void RegleAvecRoleRec::giveactif() {
	this->actifrec=true;
}

//affiche une chaine de caractères liée au role récurrent
string RegleAvecRoleRec::afficherreglerec(vector<joueur> tabjoueur, int nojoueur, vector<RegleSimple*> tabregles, int noregle) {
  stringstream ss;
  ss << tabregles[noregle]->nbgorgees;
  ss >> chainestr2;
  chainestr2 = string(tabregles[noregle]->nomregle.c_str())+string(" boit ")+chainestr2+string(" gorgees ");
  return chainestr2;
}
