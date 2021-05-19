#pragma once
#pragma once
#ifndef _RegleAvecRole_h
#define _RegleAvecRole_h
#include <iostream>
#include <string>
#include <vector>
#include "joueur.h"
#include "tour.h"
#include "RegleSimple.h"
using namespace std;

//Header de la classe RegleAvecRole

class RegleAvecRole: public RegleSimple{
public:
	RegleAvecRole(int id, string nom, int de1, int de2, int somme, int actif, int gorgees, int role);
	RegleAvecRole(const RegleAvecRole & copied_RegleAvecRole);
	int getrole();
	string afficherregle(vector<joueur> tabjoueur, int nojoueur, vector<RegleSimple*> tabregles, int noregle);
	int idrole;
  string chainestr3;
};

#endif
