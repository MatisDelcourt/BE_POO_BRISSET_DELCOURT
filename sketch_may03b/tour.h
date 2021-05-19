#pragma once
#ifndef _tour_h
#define _tour_h
#include <iostream>
#include <string>
using namespace std;

//Header de la classe tour

class tour {
public:
	tour();

	int de1;
	int de2;
	int somme;
	bool attente;

	void majtour(int lancer);

};


#endif
