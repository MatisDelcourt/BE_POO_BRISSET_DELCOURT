#include <Arduino.h>
#include <iostream>
#include <string>
#include <vector> 
#include<ctime>
#include "partie.h"
using namespace std;

//Classe qui gère la partie

//Constructeur
partie::partie() {
}

//Fonction gérant les règles
int partie::changerregles(tour tr, vector<joueur> joueur, int nojoueur) {
    int etat = 0;
    unsigned int i;

    //Si Double 6 : on ajoute une nouvelle règle
    if (tr.de1 == 6) {
        if (tr.de2 == 6){
            etat=1;
        }
    }

    //Si la somme des dés fait 7 : c'est le Bizkit ! Le dernier à mettre son pouce sur le front a perdu et boit 3 gorgées
    if (tr.somme == 7) {
        strp = string("BIZKIT!");
        Serial.println(strp.c_str());
    }

    //Si la somme des dés fait 6 : le joueur précédant le joueur actuel boit une gorgée
    if (tr.somme == 6) {
        if (nojoueur != 0) {
            strp = string(joueur[nojoueur - 1].nom.c_str())+string(" boit une gorgee !");
            Serial.println(strp.c_str());
            }
            else {
              strp = string(joueur[joueur.size() - 1].nom.c_str())+string(" boit une gorgee !");
              Serial.println(strp.c_str());
            }
      }

    //Si la somme des dés fait 8 : le joueur suivant le jouer actuel boit une gorgee
    if (tr.somme == 8) {
            if (nojoueur != joueur.size()-1) {
              strp = string(joueur[nojoueur + 1].nom.c_str())+string(" boit une gorgee !");
              Serial.println(strp.c_str());
            }
            else {
              strp = string(joueur[0].nom.c_str())+string(" boit une gorgee !");
              Serial.println(strp.c_str());
            }
        }

    for (i = 0; i < this->tabregles.size(); i++) {
        if (this->tabregles[i]->actifregle == 1) {
            if ((this->tabregles[i]->de1regle == tr.de1 and this->tabregles[i]->de2regle == tr.de2) or (this->tabregles[i]->de1regle == tr.de2 and this->tabregles[i]->de2regle == tr.de1) or (this->tabregles[i]->sommeregle == tr.somme)) {
                if (this->tabregles[i]->getrole() == 0) {
                    strp=this->tabregles[i]->afficherregle(joueur, nojoueur, this->tabregles, i);
                    Serial.println(strp.c_str());
                }
                else {
                    strp=this->tabregles[i]->afficherregle(joueur, nojoueur, this->tabregles, i);
                    Serial.println(strp.c_str());
                    this->tabregles[i]->giveactif();
                    etat = 2;
                }
            }
            if (this->tabregles[i]->getrecurrent() == true) {
                if (this->tabregles[i]->getactif() == true) {
                    if ((this->tabregles[i]->getderec() == tr.de1) or (this->tabregles[i]->getderec() == tr.de2) or (this->tabregles[i]->getsommerec() == tr.somme)) {
                        strp=this->tabregles[i]->afficherreglerec(joueur, nojoueur, this->tabregles, i);
                        Serial.println(strp.c_str());
                    }
                }
            }
        }

    }
    return etat;
}

//Fonction pour mettre à jour la partie
void partie::majpartie(tour tr, int joueur) {
    int noregle;
    unsigned int i;
    string creerregle;
    string typeregle;
    int id = 5;
    int deun = 0;
    int dedeux = 0;
    int sum = 0;
    string nom = "";
    int gorg = 0;
    int role = 5;
    int dr = 0;
    int sr = 0;

    switch (this->changerregles(tr, tabjoueur, joueur)) {
    case 1:
        nvregle=1;
        break;
    case 2:
        for (i = 0; i < tabjoueur.size(); i++)
            if (tabjoueur[i].role == this->tabregles[i]->getrole()) {
                tabjoueur[i].role = 0;
            }
        tabjoueur[joueur].role = this->tabregles[i]->getrole();
        break;
    }
}
