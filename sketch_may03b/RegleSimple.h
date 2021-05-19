#pragma once
#pragma once
#pragma once
#ifndef _RegleSimple_h
#define _RegleSimple_h
#include <iostream>
#include <string>
#include <vector>
#include "joueur.h"
#include "tour.h"
using namespace std;

//Header de la classe RegleSimple

class RegleSimple {
public:
	RegleSimple(int idregle, string nomregle, int de1, int de2, int somme, int actif, int gorgees);
	RegleSimple(const RegleSimple & copied_RegleSimple);

	virtual int getrole();
	virtual bool getrecurrent();
	virtual int getderec();
	virtual int getsommerec();
	virtual void giveactif();
	virtual bool getactif();
	virtual string afficherregle(vector<joueur> tabjoueur, int nojoueur, vector<RegleSimple*> tabregles, int noregle);
	virtual string afficherreglerec(vector<joueur> tabjoueur, int nojoueur, vector<RegleSimple*> tabregles, int noregle);
	int idregle;
	string nomregle;
	int de1regle = 0;
	int de2regle = 0;
	int sommeregle = 0;
	int actifregle;
	int nbgorgees;
  string chainestr;

};

#endif
