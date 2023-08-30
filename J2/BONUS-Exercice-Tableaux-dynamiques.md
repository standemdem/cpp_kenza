# Exercice - Tableaux dynamiques

Énoncé du TP :

Dans cet exercice, vous allez travailler sur les tableaux dynamiques en C++. Votre objectif est de créer un programme qui permet à l'utilisateur d'entrer des notes pour un groupe d'étudiants et de réaliser plusieurs opérations sur ces données.

Voici les étapes à suivre pour réaliser cet exercice :

1. Demandez à l'utilisateur combien d'étudiants il souhaite entrer et stockez cette valeur dans une variable (nombreEtudiants).
2. Créez un tableau dynamique pour stocker les notes de tous les étudiants. Le tableau doit avoir la taille fournie par l'utilisateur (nombreEtudiants). Utilisez la notation de pointeur et l'opérateur "new" pour allouer de la mémoire pour le tableau.
3. Utilisez une boucle pour demander à l'utilisateur d'entrer les notes de chaque étudiant. Assurez-vous que les notes sont comprises entre 0 et 20. Si la note entrée n'est pas valide, demandez à nouveau la note pour le même étudiant.
4. Calculez la somme et la moyenne des notes des étudiants à l'aide d'une boucle.
5. Trouvez la note la plus élevée et la note la plus basse, ainsi que les indices de ces notes dans le tableau.
6. Imprimez la somme, la moyenne, la note la plus élevée, la note la plus basse, l'indice de la note la plus élevée et l'indice de la note la plus basse.

N'oubliez pas de libérer la mémoire allouée pour le tableau à la fin du programme à l'aide de l'opérateur "delete[]".

Note : Vous pouvez ajouter des fonctions pour effectuer certaines tâches, comme demander une note valide à l'utilisateur, calculer la somme et la moyenne, trouver la note la plus élevée et la note la plus basse, etc. Cela rendra votre code plus lisible et mieux organisé.