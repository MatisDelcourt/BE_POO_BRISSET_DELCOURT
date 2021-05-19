#pragma once
#ifndef _RegleAvecRoleRec_h
#define _RegleAvecRoleRec_h
#include <iostream>
#include <string>
#include <vector>
#include "joueur.h"
#include "tour.h"
#include "RegleAvecRole.h"
using namespace std;

//Header de la classe RegleAvecRole

class RegleAvecRoleRec : public RegleAvecRole {
public:
	RegleAvecRoleRec(int id, string nom, int de1, int de2, int somme, int actif, int gorgees, int role, bool rec, int der, int sommer);
	RegleAvecRoleRec(const RegleAvecRoleRec& copied_RegleAvecRoleRec);
	bool recurrent;
	int derec;
	int sommerec;
	bool actifrec;
	virtual bool getrecurrent();
	virtual bool getactif();
	virtual int getderec();
	virtual int getsommerec();
	virtual void giveactif();
	string afficherreglerec(vector<joueur> tabjoueur, int nojoueur, vector<RegleSimple*> tabregles, int noregle);
  string chainestr2;
};

#endif
