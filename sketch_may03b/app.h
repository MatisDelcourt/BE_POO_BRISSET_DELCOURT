#pragma once
#ifndef _app_h
#define _app_h
#include <iostream>
#include <string>
#include "partie.h"
#include "tour.h"
#include "de.h"
#include "RegleAvecRole.h"
#include "RegleAvecRoleRec.h"
#include "RegleSimple.h"
using namespace std;

//Header de la classe app

class app {

public:
	app();
	void jeu();
	partie mapartie;
	int nojoueur = 0;
	tour tr;
	de mon_de;
  char* caraca = "Partie en cours";
  string stra = "Debut de partie";
	int nbrtours;
	int nbjoueurs;

};

#endif
