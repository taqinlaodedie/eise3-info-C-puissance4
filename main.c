#include <stdio.h>
#include "main.h"
#include "jeuPuissance4.h"

int nbCoupsJoues;
int grille[7][6];//nb de jeton dans chaque colonne
int joueur = ROUGE;

int main (void)
{
	int res = 0;
	int i,j;

	for (i = 0; i < 7; i ++) {
		for (j = 0; j <6; j ++) {
			grille[i][j] = VIDE;
		}
	}
	while (1){
		if (joueur == JAUNE) {
			joueur = ROUGE;
		}
		else
		{
			joueur = JAUNE;
		}
		res = jouerPartiePuissance4 ();
		if (res == 1) {
			break;
		}
	}
	
	return (0);
}