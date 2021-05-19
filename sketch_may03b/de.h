#pragma once
#include <math.h>
#include <ChainableLED.h>

//Header de la classe dé

class de
{
public:
  ChainableLED leds{ChainableLED(13,15,7)};
  de();
  void afficheDe(int nombre);
  void eteintDe();
	int valDe;
  void majde();

  private:
const int ECART = 20; //écart de luminosité fixé à 20
const int TEMPO = 500;

//variables pour détecter un changement de luminosité
int luminosity1;
int luminosity2;

};
