# Jeu de dés innovant : le Bizkit !

C'est un programme complet qui permet d'initialiser une nouvelle partie avec le nombre de joueurs souhaité et leurs noms. 
Il faut une connexion Wi-Fi : avec identifiant et mot de passe à remplacer dans la fonction Init_Server de la classe AffichagePortable.

## Compilation et exécution

Compilez et téléversez le programme vers la carte.
Sur le téléphone, se connectez à l'adresse IP indiquée par le moniteur série une fois que le Wi-Fi est établi. 
Suivre les indications du jeu au début de la partie : saisie du nombre de joueurs et leurs noms.
Une fois l'initialisation effectuée, on peut commencer à lancer le dé en prenant le capteur de lumière dans sa main (pour changer la luminosité détectée).

Lors de la création d'une nouvelle règle :
	- le bouton RegleSimple permet de créer une règle basique sans attribution de rôle. (ex : "Si dé1=2 et dé2=3, le joueur boit trois gorgées")
	- le bouton RegleAvecRole permet de créer une règle avec une attribution de rôle. (ex : "Si la somme des dés est égale à 10, le joueur devient la reine des questions")
	- le bouton RegleRoleRecurrent permet de créer une règle avec une attribution de rôle qui marche de manière récurrente. (ex : "Si la somme des dés est égale à 4, le joueur devient la noisette. Par la suite, à chaque fois qu'un 3 est lancé, il boit une gorgée.")

Le jeu s'arrête quand on se déconnecte de la page ou du Wi-Fi.