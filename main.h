#include <stdio.h>
#include <stdbool.h>

#define VIDE    0
#define ROUGE   (-1)
#define JAUNE   1
#define NB_LIG_GRILLES_MODELES 12
#define NB_COL_GRILLE_MODELE   13
#define NB_LIG_GILLES_VUES     6
#define NB_COL_GILLE_VUES      7
#define CONFIGURATION_GAGNANTE 4
#define DECALAGE               3

extern int nbCoupsJoues;
extern int grille[7][6];//nb de jeton dans chaque colonne
extern int joueur;