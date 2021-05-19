#include <Arduino.h>
#include "de.h"
#include<iostream>
#include<string>
using namespace std;

//Classe qui gère le dé électronique

//Constructeur
de::de(){
  ChainableLED leds{ChainableLED(13,15,7)}; //initialisation des leds composant le dé
  this->leds.init();
};

//Fonction qui allume les LEDS en fonction du score du dé 
void de::afficheDe(int nombre){

  //si score du dé = 1
  if(nombre==1){
    for (int i=0;i<7;i++) {
      if (i==3)
        leds.setColorRGB(i,255,0,0); //on allume la LED du milieu (correspondant à la LED3)
      else
        leds.setColorRGB(i,0,0,0); //on éteint les autres
    }
  }

  //si score du dé = 2
  if(nombre==2){
    for (int i=0;i<7;i++) {
      if (i==1 | i==5)
        leds.setColorRGB(i,255,0,0); //On allume les LED 2 et 5
      else
        leds.setColorRGB(i,0,0,0); //les autres sont éteintes
    }
  }

  //Si score du dé = 3
  if(nombre==3){
    for (int i=0;i<7;i++) {
      if (i==1 | i==3 | i==5)
        leds.setColorRGB(i,255,0,0); //on allume les LED 1, 3 et 5
      else
        leds.setColorRGB(i,0,0,0); //les autres sont éteintes
    }
  }

  //Si score du dé = 4
  if(nombre==4){
    for (int i=0;i<7;i++) {
      if (i==2 | i==3 | i==4)
        leds.setColorRGB(i,0,0,0); //on éteint les LEDS 2, 3 et 4
      else
        leds.setColorRGB(i,255,0,0); //les autres sont allumées
    }
  }

  //Si score du dé = 5
  if(nombre==5){
    for (int i=0;i<7;i++) {
      if (i==2 | i==4)
        leds.setColorRGB(i,0,0,0); //on éteint les LEDS 2 et 4
      else
        leds.setColorRGB(i,255,0,0); //les autres sont allumées
    }
  }

  //Si score du dé = 6
  if(nombre==6){
    for (int i=0;i<7;i++) {
      if (i==3)
        leds.setColorRGB(i,0,0,0); //on éteint la LED 3
      else
        leds.setColorRGB(i,255,0,0); //les autres sont allumées
    }
  }
  
}

//Fonction qui éteint le dé (toutes les LEDS)
void de::eteintDe(){
   for(int i=0;i<7;i++){
     leds.setColorRGB(i,0,0,0); //aucune LED n'est allumée
  }
}

//Fonction qui met à jour le dé
void de::majde() {

  //On compare la valeur de luminosité détectée par le capteur de lumière
  int luminosity1 = analogRead(0);
  delay(500);
  int luminosity2 = analogRead(0);

  if (abs(luminosity1-luminosity2) > ECART) { //si l'écart entre les deux valeurs est suffisante, alors on lance le dé
    eteintDe(); //on éteint le dé pour le reset
    Serial.println("Dé lancé");
    valDe=random(1,7); //valeur aléatoire entre 1 et 6 (pour un jeu non pipé !)
    Serial.print("Score du dé : ");
    Serial.println(valDe);
    afficheDe(valDe); //on affiche avec les LEDS la valeur du dé
  }
}
