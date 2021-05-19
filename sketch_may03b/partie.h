#pragma once
#ifndef _partie_h
#define _partie_h
#include <iostream>
#include <vector> 
#include <string>
#include "joueur.h"
#include "tour.h"
#include "RegleAvecRole.h"
#include "RegleAvecRoleRec.h"
#include "RegleSimple.h"
using namespace std;

//Header de la classe partie

class partie {
public:
  partie();
  int nbreglesinactives;
  int nbjoueurs;
  vector<joueur> tabjoueur;
  vector<RegleSimple*> tabregles;
  string strp;

  int changerregles(tour tr, vector<joueur> tabjoueur, int nojoueur);
  void majpartie(tour tr, int joueur);

  int nvregle = 0;
  bool non = false;
};

#endif
