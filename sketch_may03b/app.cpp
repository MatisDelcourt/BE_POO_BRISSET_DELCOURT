#include <Arduino.h>
#include <iostream>
#include <string>
#include "app.h"
using namespace std;
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

//Classe pour gérer le jeu

app::app() {
    string nomjoueur;
    int j;

    this->tr.de1 = 0; // on remet la valeur des dés à zéro
    this->tr.de2 = 0;
    this->tr.somme = 0; //on remet la valeur de la somme des dés à zéro
    this->tr.attente = false; //on remet à false la variable nécessaire pour passer au joueur suivant

    this->mon_de.valDe = -1;

    //Base de données des nouvelles règles pré-remplies mais pas encore actives au début du jeu
    this->mapartie.tabregles.push_back(new RegleAvecRole(1, "le roi des pouces",0, 0, 9, 0,0, 2));
    this->mapartie.tabregles.push_back(new RegleAvecRole(2, "la reine des questions", 0, 0, 10, 0, 0, 3));
    this->mapartie.tabregles.push_back(new RegleAvecRole(3, "le freeze", 0, 0, 4, 0, 0, 4));
    this->mapartie.tabregles.push_back(new RegleAvecRoleRec(4, "la noisette", 0, 0, 3, 0, 3, 5, true, 3, 0));

   //Pour setup lavariable nbreglesinactives
    unsigned int k;
    this->mapartie.nbreglesinactives = 0;
    for (k = 0; k < this->mapartie.tabregles.size(); k++) {
        if (this->mapartie.tabregles[k]->actifregle == 0) {
            this->mapartie.nbreglesinactives++;
        }
    } 

};

//Fonction qui gère quand on lance les dés et le tour par tour
void app::jeu() {
        mon_de.majde();
        if (mon_de.valDe != -1) {
            tr.majtour(mon_de.valDe);
            if (tr.attente == false) {
                mapartie.majpartie(tr, nojoueur);
                stra = mapartie.strp;
                caraca = (char*)stra.c_str(); 

                if (nojoueur < nbjoueurs - 1) {
                    nojoueur++;
                }
                else {
                    nojoueur = 0;                
                };
            }
            else {
            }
            mon_de.valDe = -1;  
        }
};
