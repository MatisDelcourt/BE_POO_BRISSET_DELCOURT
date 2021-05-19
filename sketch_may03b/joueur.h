#pragma once
#ifndef _joueur_h
#define _joueur_h
#include <iostream>
#include <string>
using namespace std;

//Header de la classe joueur

class joueur {
public:
	joueur(int nojoueur, string nomjoueur, int nrole);
	joueur(const joueur & copied_joueur);

	int no;
	string nom;
	int role;
};

#endif
