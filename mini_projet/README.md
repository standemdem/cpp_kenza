# PROJET C++

## Objectifs:
* Créer un générateur de fichiers
  1. Génération de la Classe via input utilisateur
  2. Génération des Fichiers (classe.h classe.cpp main.cpp makefile)
  3. Tester le programme dans main.cpp

## Fonctionnement du projet

Une fois le fichier .zip récupéré, il faut le dézipper dans un dossier.

Pour générer les fichiers .cpp, .h et le makefile demandés, il faut compiler les fichiers .cpp et .h à l'aide de la commande suivante
```bash
g++ *.cpp *.h
``` 
Il faut ensuite éxecuter le fichier a.out (Linux) ou a.exe (Windows)
```bash
# Sous Linux
./a.out
``` 
```powershell
# sous Windows
.\a.exe
```
La console demande à l'utilisateur de rentrer:
* Un nom de classe
* Un choix <(y/n)> de personnalisation de typage
* Une demande d'input utilisateur pour définition des attributs de la classe. 

La commande génère ensuite les fichiers suivants:

- Un fichier <nom_de_la_classe> (.h) contenant ld prototype complet de la classe.
- Un fichier <nom_de_la_classe> (.cpp) contenant la declaration de la classe et les implémentations des méthodes de la classe.
- Un fichier main.cpp avec des tests pour la classe générée.
- Un Makefile qui compile le projet avec g++.

Pour générer l'executable tapper la commande suivate:
```bash
make
```
Les commandes pour gérer le projet via le makefile sont:
``` bash
# Executer le projet et faire les tests contenu dans le main.cpp
make run
# Supprimer tous les fichiers générés, makefile y compris
make clean
```