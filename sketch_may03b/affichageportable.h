// Load Wi-Fi library

#ifndef AFFICHAGEPORTABLE_H
#define AFFICHAGEPORTABLE_H
#include <ESP8266WiFi.h>
#include "app.h"

//Header de la classe AffichagePortable

class AffichagePortable{

  public :
  char *ssid; //Identifiant wifi
  char *password; //Mot de passe wifi
  WiFiServer server;
  WiFiClient client;
  String currentLine = "";// make a String to hold incoming data from the client

  // Variable to store the HTTP request
  String header;

  // variables nbjoueurs
  int index_nbj = 0;
  String char_nbj = "";
  int nbj = 0;

  // variables nomjoueur
  int index_nomj = 0;
  String char_nomj = "";

  //variables condition pour le changement des pages HTML
  int loadpage = 0;
  int type;

  //variable de comparaison
  String cmp;

  //variables condition dé 1
  int index_de1;
  String char_de1 = "";
  int cdt_de1;

//variables condition dé 2
  int index_de2;
  String char_de2 = "";
  int cdt_de2;

  //variables somme
  int somme;
  int index_somme;
  String char_somme = "";  


  //variables nb de gorgées
  int gorgee;
    int index_gorgee;
  String char_gorgee = "";  

  //variables nom du role
    int index_nr;
  String char_nr = "";  
  String nom_role;
  
  //variables dé récurrent
  int de_rec;
  int index_derec;
  String char_derec;

  //variables somme récurrente des dés 
  int somme_rec;
  int index_sommerec;
  String char_sommerec;

  //variables pour la création des nouvelles règles
  int idregle = 4;
  int idrole=4;
/**
   * @brief Create a wifi server
   * @param char* id: network name
   *        char* pw: password of network
   * @return none
   */
  void Open_Wifi_Server(char* id, char* pw);

  /**
   * @brief Connect to a WiFi network
   * @param none
   * @return none
   */
  void Connect_To_Wifi_Network(void);

  /**
   * @brief Begin the web server and print IP
   * @param none
   * @return none
   */
  void Start_Wifi_Server(void);

  void Set_Nb_Joueurs(app &mon_jeu);

  bool Set_Nom_Joueurs(app &mon_jeu, int numj);

  void Set_Condition_De1(app &mon_jeu);
  void Set_Condition_De2(app &mon_jeu);
  void Set_Somme(app &mon_jeu);
  void Set_Nom_Role(app &mon_jeu);
  void Set_Gorgees(app &mon_jeu);
  void Set_Condition_De_Rec(app &mon_jeu);
  void Set_Somme_Rec(app &mon_jeu);

 /**
   * @brief Manage the html display
   * @param none
   * @return none
   */
void Html_Display(app &mon_jeu);

   
 /**
   * @brief Update new_sheet/start_recording/choose_file values according to the URL
   * @param none
   * @return none
   */
  void Get_URL(app &mon_jeu);

  public:
  // Current time
  unsigned long currentTime = millis();
  // Previous time
  unsigned long previousTime = 0;
  // Define timeout time in milliseconds (example: 2000ms = 2s)
  const long timeoutTime = 2000;
  AffichagePortable();
   /**
   * @brief Init a web server
   * @param none
   * @return none
   */
  void Init_Server(void);

  /**
   * @brief Wait and connect a client to the web server
   * @param none
   * @return none
   */
  void Start_Client_Connection(void);


  /**
   * @brief Close the client connection
   * @param none
   * @return none
   */
  void Close_Client_Connection(void);


/**
   * @brief Get client data and manage html display
   * @param none
   * @return none
   */
  void Manage_App(app &mon_jeu);

  };

  #endif
