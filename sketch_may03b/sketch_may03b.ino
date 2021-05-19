#include <Arduino.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <ChainableLED.h>
#include "affichageportable.h"
#include "joueur.h"
#include "partie.h"
#include "tour.h"
#include "app.h"
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

//GOOD VERSION

U8G2_SH1107_SEEED_128X128_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE); //Initialisation écran LCD
app nvjeu;
AffichagePortable aff;

void setup() {  
  Serial.begin(9600);
  aff.Close_Client_Connection();
  aff.Init_Server();
  u8g2.begin();
}

void loop() {

  //affichage permanent de l'écran LCD
  u8g2.setFont(u8g2_font_ncenB10_tr); //set display parameters
  u8g2.clearBuffer();
//  u8g2.setCursor(0,24);
//  u8g2.print("Au tour de?");
  u8g2.setCursor(0,72);
  u8g2.print("Score du de 1 : ");
  u8g2.setCursor(0,96);
  u8g2.print("Score du de 2 : ");
  u8g2.sendBuffer();
  
  aff.Start_Client_Connection();
  
  nvjeu.jeu();
  aff.Manage_App(nvjeu);
  yield();
  
  if (nvjeu.tr.de1 != 0) {
    u8g2.setCursor(120,72);
    u8g2.print(nvjeu.tr.de1); //affiche la valeur du dé 1 sur l'écran
    u8g2.sendBuffer();
    if (nvjeu.tr.attente == true) {
      if (nvjeu.tr.de2 != 0) {
        u8g2.setCursor(120,96); 
        u8g2.print("");
        u8g2.sendBuffer(); }
    }
  if (nvjeu.tr.de2 != 0) {
  u8g2.setCursor(120,96);
  u8g2.print(nvjeu.tr.de2);
  u8g2.sendBuffer();
  }
//
//  u8g2.setCursor(0,40);
//  u8g2.print(nvjeu.mapartie.tabjoueur[nvjeu.mapartie.tabjoueur.nojoueur+1].nom.c_str());
//  u8g2.sendBuffer();
}
}
