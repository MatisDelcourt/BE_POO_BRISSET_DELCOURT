#include "affichageportable.h"
#include<ctime>

//Classe qui gère la connexion et l'affichage HTML

//Constructeur
AffichagePortable::AffichagePortable():server(80){}//constructor who initializes server http : port 80

//Initialiser le serveur
void AffichagePortable::Open_Wifi_Server(char* id, char* pw){
  // Replace with your network credentials
  this->ssid = id ;
  Serial.println(this->ssid);
  this->password = pw;
}

//Se connecter au wi-fi
void AffichagePortable::Connect_To_Wifi_Network(void){
  Serial.print("Connecting to ");
  Serial.println(this->ssid);
  WiFi.begin(this->ssid, this->password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

//Démarrer le serveur
void AffichagePortable::Start_Wifi_Server(void){
   // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  this->server.begin();
}

//Démarre la connexion avec le client
void AffichagePortable::Start_Client_Connection(void){
  this->client = this->server.available();   // Listen for incoming client
  if (this->client) {                             // If a new client connects,
  Serial.println("New Client.");          // print a message out in the serial port
  this->currentTime = millis();
  this->previousTime = this->currentTime;
  }
}

//Initialise le serveur
void AffichagePortable::Init_Server(void){
  Open_Wifi_Server("AndroidAP", "gfib3372");
//  Open_Wifi_Server("Lipton", "douzedouze");
  Connect_To_Wifi_Network();
  Start_Wifi_Server();
}


//Ferme la connexion avec le client
void AffichagePortable::Close_Client_Connection(void){
 if (this->client){
// Clear the header variable
   header = "";
   // Close the connection
   this->client.stop();
   Serial.println("Client disconnected.");
    Serial.println("");
 }
}

//Définit le nombre de joueurs
void AffichagePortable::Set_Nb_Joueurs(app &mon_jeu) {
  if (header.indexOf("Nbjoueurs") != -1) { 
    index_nbj = header.indexOf("Nbjoueurs")+10; //renvoie l'index du premier caractère de nbjoueurs (?Nbjoueurs=.)
    Serial.print("Nombre de joueurs = ");
    while (header[index_nbj] != 'H' and header[index_nbj] != 'A') {
      char_nbj += header[index_nbj];
      index_nbj++;
    }
    Serial.println(char_nbj);
    nbj = atoi(char_nbj.c_str());
    mon_jeu.nbjoueurs = nbj;
    cmp = header;
    header="";
    char_nbj="";
  }
}

//Définit le nom de chaque joueur
bool AffichagePortable::Set_Nom_Joueurs(app &mon_jeu, int numj) {
  if (header != cmp) { //on vérifie si le nom est pas déjà donné à quelqu'un
   if (header.indexOf("Nomjoueur") != -1) { 
    index_nomj = header.indexOf("Nomjoueur")+10; //renvoie l'index du premier caractère de Nomjoueur (?Nomjoueur=.)
    Serial.print("Nom du joueur = ");
    while (header[index_nomj] != 'H' and header[index_nomj] != 'A') {
        char_nomj += header[index_nomj];
        index_nomj++;
    }
    mon_jeu.mapartie.tabjoueur.push_back(joueur(numj,char_nomj.c_str(),0));
    Serial.println(char_nomj);
    cmp = header;
    Serial.println(cmp);
    char_nomj = "";
    header="";
    return true;
    }
    return false;
  }
  else {
  return false;
  }
}

//Définit la condition sur le dé 1 quand on invente une nouvelle règle
void AffichagePortable::Set_Condition_De1(app &mon_jeu) {
  if (header.indexOf("De1") != -1) {
    index_de1 = header.indexOf("De1")+4; //renvoie l'index du première caractère de De1
    Serial.print("Condition du de 1 = ");
    while (header[index_de1] != 'H' and header[index_de1] != 'A') {
      char_de1 += header[index_de1];
      index_de1++;
    }
    Serial.println(char_de1);
    cdt_de1 = atoi(char_de1.c_str());
    header="";
    char_de1="";
  }
}

//Définit la condition sur le dé 2 quand on invente une nouvelle règle
void AffichagePortable::Set_Condition_De2(app &mon_jeu) {
  if (header.indexOf("De2") != -1) {
    index_de2 = header.indexOf("De2")+4; //renvoie l'index du première caractère de De2
    Serial.print("Condition du de 2 = ");
    while (header[index_de2] != 'H' and header[index_de2] != 'A') {
      char_de2 += header[index_de2];
      index_de2++;
    }
    Serial.println(char_de2);
    cdt_de2 = atoi(char_de2.c_str());
    header="";
    char_de2="";
  }
}

//Définit la condition sur la somme des dés quand on invente une nouvelle règle
void AffichagePortable::Set_Somme(app &mon_jeu) {
  if (header.indexOf("Somme") != -1) {
    index_somme = header.indexOf("Somme")+6; //renvoie l'index du première caractère de Somme
    Serial.print("Condition Somme = ");
    while (header[index_somme] != 'H' and header[index_somme] != 'A') {
      char_somme += header[index_somme];
      index_somme++;
    }
    Serial.println(char_somme);
    somme = atoi(char_somme.c_str());
    header="";
    char_somme="";
  }
}

//Définit le nom du nouveau rôle quand on invente une nouvelle règle
void AffichagePortable::Set_Nom_Role(app &mon_jeu) {
  if (header.indexOf("Nom") != -1) {
    index_nr = header.indexOf("Nom")+4; 
    Serial.print("Nom du role = ");
    while (header[index_nr] != 'H' and header[index_nr] != 'A') {
      char_nr += header[index_nr];
      index_nr++;
    }
    Serial.println(char_nr);
    nom_role = String(char_nr.c_str());
    header="";
    char_nr="";
  }
}

//Définit le nombre de gorgées à donner quand on invente une nouvelle règle
void AffichagePortable::Set_Gorgees(app &mon_jeu) {
  if (header.indexOf("Gorgees") != -1) {
    index_gorgee = header.indexOf("Gorgees")+8; 
    Serial.print("Condition Nombre de Gorgees = ");
    while (header[index_gorgee] != 'H' and header[index_gorgee] != 'A') {
      char_gorgee += header[index_gorgee];
      index_gorgee++;
    }
    Serial.println(char_gorgee);
    gorgee = atoi(char_gorgee.c_str());
    header="";
    char_gorgee="";
  }
}

//Définit la condition sur le dé quand on invente une nouvelle règle récurrente
void AffichagePortable::Set_Condition_De_Rec(app &mon_jeu) {
  if (header.indexOf("DeRec") != -1) {
    index_derec = header.indexOf("DeRec")+6; 
    Serial.print("Condition du de recurrent = ");
    while (header[index_derec] != 'H' and header[index_derec] != 'A') {
      char_derec += header[index_derec];
      index_derec++;
    }
    Serial.println(char_derec);
    de_rec = atoi(char_derec.c_str());
    header="";
    char_derec="";
  }
}

//Définit la condition sur la somme des dés quand on invente une nouvelle règle récurrente
void AffichagePortable::Set_Somme_Rec(app &mon_jeu) {
  if (header.indexOf("SommeRec") != -1) {
    index_sommerec = header.indexOf("SommeRec")+9; 
    Serial.print("Condition Somme récurrente = ");
    while (header[index_sommerec] != 'H' and header[index_sommerec] != 'A') {
      char_sommerec += header[index_sommerec];
      index_sommerec++;
    }
    Serial.println(char_sommerec);
    somme_rec = atoi(char_sommerec.c_str());
    header="";
    char_sommerec="";
  }
}

//Fonction qui affiche les différentes pages HTML en fonction du déroulement du jeu
void AffichagePortable::Html_Display(app &mon_jeu){
  if (loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==0) {
    //PAGE JEU PRINCIPAL
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    this->client.println("<meta http-equiv=\"refresh\" content=\"1\">"); //rafraîchit la page toutes les secondes
    this->client.println("<link rel=\"icon\" href=\"data:,\">");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #FDD017; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    
    this->client.println("<body><h1>LE JEU DU BIZKIT</h1>");

    this->client.println(mon_jeu.caraca); //affiche l'action à faire 
    this->client.println("<p><a href=\"/JEUENCOURS\"><p>");
  }
  
  else if (loadpage==0) {   
    //PAGE SAISIE DU NOMBRE DE JOUEURS
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #DAF7A6; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    this->client.println("<body><h1>SAISIE DU NOMBRE DE JOUEURS</h1>");
    this->client.println("<form><label for=\"Nbjoueurs\">Indiquez le nombre de joueurs pour la partie et appuyez sur \"enter\" :</label> <input type=\"text\" id=\"Nbjoueurs\" name=\"Nbjoueurs\"></form><br>"); //Saisie du nombre de joueurs
    this->client.println("<p>Suivant !<br></p></body></html>");
    }

  else if (loadpage>0 and loadpage<=mon_jeu.nbjoueurs) { 
    //PAGE SAISIE DES NOMS DES JOUEURS
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #86F3D2; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println("body{background-color : #FFEBED};}</head></style>");
    this->client.println("<body><h1>SAISIE DU NOM DES JOUEURS</h1>");
    this->client.println("<form><label for=\"Nomjoueur\">Indiquez le nom du joueur et appuyez sur \"enter\" :</label> <input type=\"text\" id=\"Nomjoueur\" name=\"Nomjoueur\"></form><br>"); //Saisie du nom des joueurs
    this->client.println("<p>On demarre bientot ?<br></p></body></html>");
  }

  else if (loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==1) {
    //PAGE NOUVELLE REGLE A DEFINIR
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    this->client.println("<link rel=\"icon\" href=\"data:,\">");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #FDD017; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    
    this->client.println("<body><h1>LE JEU DU BIZKIT</h1>");
    //Ajouter une nouvelle règle ?
    this->client.println("Voulez-vous ajouter une nouvelle regle ?"); 
    this->client.println("<p><a href=\"/OUI\"><button class=\"button\">OUI</button></a></p>"); //Bouton oui si on veut inventer nous-même une nouvelle règle
    this->client.println("<p><a href=\"/NON\"><button class=\"button\">NON</button></a></p>"); //Bouton non si on veut prendre une règle déjà établie
  }
    else if (loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==11) {
    //PAGE DE CONTROLE
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    this->client.println("<link rel=\"icon\" href=\"data:,\">");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #FDD017; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    
    this->client.println("<body><h1>LE JEU DU BIZKIT</h1>");
    //Bouton OK pour repasse à la page du jeu en cours
    this->client.println("<p><a href=\"/OK\"><button class=\"button\">OK</button></a></p>");
  }

    else if (loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==2) {
    //PAGE CHOISIR LE TYPE DE REGLES
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    this->client.println("<link rel=\"icon\" href=\"data:,\">");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #FDD017; border: none; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button3 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    
    this->client.println("<body><h1>LE JEU DU BIZKIT</h1>");
    //Quel type de règle ?
    this->client.println("Quel type de regle voulez-vous?");
    this->client.println("<p><a href=\"/REGLE_SIMPLE\"><button class=\"button\">REGLE_SIMPLE</button></a></p>"); //Bouton pour une règle simple
    this->client.println("<p><a href=\"/REGLE_AVEC_ROLE\"><button class=\"button\">REGLE_AVEC_ROLE</button></a></p>"); //Bouton pour une règle avec role simple
    this->client.println("<p><a href=\"/REGLE_ROLE_RECURRENT\"><button class=\"button\">REGLE_ROLE_RECURRENT</button></a></p>"); //Bouton pour une règle avec role récurrent
  }
  else if (loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==3) {   
    //PAGE SAISIE CONDITION DU DE 1
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #DAF7A6; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    this->client.println("<body><h1>SAISIE DE LA CONDITION SUR LE DE 1</h1>");
    this->client.println("<form><label for=\"De1\">Indiquez la condition sur le de 1 et appuyez sur \"enter\" :</label> <input type=\"text\" id=\"De1\" name=\"De1\"></form><br>"); // entrée condition dé 1
    this->client.println("<p>OK !<br></p></body></html>");
    }
  else if (loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==4) {   
    //PAGE SAISIE CONDITION DE2
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #DAF7A6; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    this->client.println("<body><h1>SAISIE DE LA CONDITION SUR LE DE 2</h1>");
    this->client.println("<form><label for=\"De2\">Indiquez la condition sur le de 2 et appuyez sur \"enter\" :</label> <input type=\"text\" id=\"De2\" name=\"De2\"></form><br>"); // entrée condition dé 2
    this->client.println("<p>OK !<br></p></body></html>");
    }  
  else if (loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==5) {   
    //PAGE SAISIE CONDITION SOMME
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #DAF7A6; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    this->client.println("<body><h1>SAISIE DE LA CONDITION SUR LA SOMME DES DES</h1>");
    this->client.println("<form><label for=\"Somme\">Indiquez la condition sur la somme des dés et appuyez sur \"enter\" :</label> <input type=\"text\" id=\"Somme\" name=\"Somme\"></form><br>"); // entrée condition somme
    this->client.println("<p>OK !<br></p></body></html>");
    }      
    else if (loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==6) {   
    //PAGE SAISIE NOM DU ROLE
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #DAF7A6; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    this->client.println("<body><h1>SAISIE DE LA CONDITION SUR LE NOM DU ROLE</h1>");
    this->client.println("<form><label for=\"Nom\">Indiquez le nom du nouveau role et appuyez sur \"enter\" :</label> <input type=\"text\" id=\"Nom\" name=\"Nom\"></form><br>"); //Saisie du nom du role pour la nouvelle règle
    this->client.println("<p>OK !<br></p></body></html>");
    }     
  else if (loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==7 and (type==0 or type==2)) {   
    //PAGE SAISIE NOMBRE DE GORGEES
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #DAF7A6; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    this->client.println("<body><h1>SAISIE DE LA CONDITION SUR LE NB DE GORGEES</h1>");
    this->client.println("<form><label for=\"Gorgees\">Indiquez la condition sur le nombre de gorgees et appuyez sur \"enter\" :</label> <input type=\"text\" id=\"Gorgees\" name=\"Gorgees\"></form><br>"); // entrée condition nb gorgées
    this->client.println("<p>OK !<br></p></body></html>");
    }   
    else if (loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==8 and type==2) {   
    //PAGE SAISIE CONDITION DU DE RECURRENT
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #DAF7A6; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    this->client.println("<body><h1>SAISIE DE LA CONDITION SUR LE DE RECURRENT</h1>");
    this->client.println("<form><label for=\"DeRec\">Indiquez la condition sur le de recurrent et appuyez sur \"enter\" :</label> <input type=\"text\" id=\"DeRec\" name=\"DeRec\"></form><br>"); // entrée condition dé récurrent
    this->client.println("<p>OK !<br></p></body></html>");
    }  
      else if (loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==9 and type==2) {   
        //PAGE SAISIE CONDITION SOMME RECURRENTE
    this->client.println("<!DOCTYPE html><html>");
    this->client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    this->client.println(".button { background-color: #DAF7A6; border: none; color: white; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    this->client.println(".button2 {background-color: #FFFFFF; border: solid; color: black; padding: 16px 40px;");
    this->client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
    this->client.println("<body><h1>SAISIE DE LA CONDITION SUR LA SOMME RECURRENTE DES DES</h1>");
    this->client.println("<form><label for=\"SommeRec\">Indiquez la condition sur la somme recurrente des des et appuyez sur \"enter\" :</label> <input type=\"text\" id=\"SommeRec\" name=\"SommeRec\"></form><br>"); // entrée condition somme récurrente
    this->client.println("<p>OK !<br></p></body></html>");
    }      
}

//Fonction qui gère les saisies ou les boutons sur la page HTML
void AffichagePortable::Get_URL(app &mon_jeu){
  int tab=0;

  //Pour la saisie du nombre de joueurs
  if (header.indexOf("?")>=0 and loadpage==0 and mon_jeu.mapartie.nvregle ==0) {
    Set_Nb_Joueurs(mon_jeu);
    loadpage++;
  }

  //Pour la saisie des noms des joueurs
  else if (header.indexOf("?")>=0  and loadpage>0 and loadpage <= mon_jeu.nbjoueurs and mon_jeu.mapartie.nvregle ==0) {
    if (Set_Nom_Joueurs(mon_jeu,tab)) {
      loadpage++;
      tab++;
   }
  }

  //Pour implémenter une règle déjà établie dans la BDD
  else if (header.indexOf("GET /NON")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==1) {
    srand((unsigned int)time(0));
    int noregle = rand() % 4;
    if (mon_jeu.mapartie.nbreglesinactives > 0) {
         while (mon_jeu.mapartie.tabregles[noregle]->actifregle == 1) {
            noregle = rand() % 4;
          };
          mon_jeu.mapartie.tabregles[noregle]->actifregle = 1;
          mon_jeu.mapartie.strp = string(mon_jeu.mapartie.tabregles[noregle]->nomregle);
          //Serial.println(mon_jeu.mapartie.strp.c_str());
          mon_jeu.mapartie.nbreglesinactives--;
     }
     else {
         mon_jeu.mapartie.strp=string("pas de règles à ajouter");
     }
     mon_jeu.mapartie.nvregle = 11;
  }

  //Pour inventer nous même une nouvelle règle
  else if (header.indexOf("GET /OUI")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==1) {
    mon_jeu.mapartie.nvregle = 2;
  }

  //Pour une règle simple
  else if (header.indexOf("GET /REGLE_SIMPLE")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==2) {
    mon_jeu.mapartie.nvregle = 3;
    type = 0; //règle simple = 0
  }

  //pour une règle avec un rôle simple
  else if (header.indexOf("GET /REGLE_AVEC_ROLE")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==2) {
    mon_jeu.mapartie.nvregle = 3;
    type = 1; //règle avec role = 1
  }

  //pour une règle avec un role récurrent
  else if (header.indexOf("GET /REGLE_ROLE_RECURRENT")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==2) {
    mon_jeu.mapartie.nvregle = 3;
    type = 2; //règle avec role récurrent = 2
  }

  //pour la condition sur le dé 1
  else if (header.indexOf("?")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==3) {
    mon_jeu.mapartie.nvregle =4;
    Set_Condition_De1(mon_jeu);
  }

  //pour la condition sur le dé 2
  else if (header.indexOf("?")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==4) {
    mon_jeu.mapartie.nvregle =5;
    Set_Condition_De2(mon_jeu);
  }  

  //pour la condition sur la somme des dés
  else if (header.indexOf("?")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==5) {
    mon_jeu.mapartie.nvregle =6;
    Set_Somme(mon_jeu);
  }    

  //pour la saisie du nom du nouveau role
    else if (header.indexOf("?")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==6) {
    mon_jeu.mapartie.nvregle =7;
    Set_Nom_Role(mon_jeu);
  }    

  //pour la saisie du nombre de gorgées
  else if (header.indexOf("?")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==7 and type!=1) {
    mon_jeu.mapartie.nvregle =8;
    Set_Gorgees(mon_jeu);
  }      

  //pour rajouter au jeu la nouvelle règle inventée avec toutes les conditions 
  else if (header.indexOf("?")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle==7 and type==1) {
    mon_jeu.mapartie.tabregles.push_back(new RegleAvecRole(idregle, nom_role.c_str(), cdt_de1, cdt_de2, somme, 1, gorgee, idrole));
    idrole++;
    idregle++;
    mon_jeu.mapartie.nvregle=0;   
  }      

  //pour la condition sur le dé récurrent
  else if (header.indexOf("?")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==8 and type==2) {
    mon_jeu.mapartie.nvregle =9;
    Set_Condition_De_Rec(mon_jeu);
}
  
  //Pour rajouter au jeu la nouvelle règle simple avec toutes les conditions
  else if (header.indexOf("?")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==8 and type==0) {
    mon_jeu.mapartie.tabregles.push_back(new RegleSimple(idregle, nom_role.c_str(), cdt_de1, cdt_de2, somme, 1, gorgee));
    idregle++;
    mon_jeu.mapartie.nvregle=0;   
  }    

  //Pour la condition sur la somme récurrente des dés
    else if (header.indexOf("?")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==9 and type==2) {
    mon_jeu.mapartie.nvregle = 10;
    Set_Somme_Rec(mon_jeu);
}

  //Pour la page temporaire avant de retourner au jeu
    else if (header.indexOf("GET /OK")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==11) {
    mon_jeu.mapartie.nvregle = 0;
}

//Pour rajouter au jeu la nouvelle règle avec rôle récurrent avec toutes les conditions
  else if (header.indexOf("?")>=0 and loadpage==mon_jeu.nbjoueurs+1 and mon_jeu.mapartie.nvregle ==10 and type==2) {
    mon_jeu.mapartie.tabregles.push_back(new RegleAvecRoleRec(idregle, nom_role.c_str(), cdt_de1, cdt_de2, somme, 1, gorgee, idrole, true, de_rec, somme_rec));
    idregle++;
    idrole++;
    mon_jeu.mapartie.nvregle=0;   
  }    
}

//Gère l'affichage HTML et les variables en fonction du déroulement de la partie
void AffichagePortable::Manage_App(app &mon_jeu){
   if (client) {
     while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            //Gère les pages HTML à afficher
            Get_URL(mon_jeu);
            Html_Display(mon_jeu);
            header="";

            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
  }
}
