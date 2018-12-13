#include <stdio.h>
#include "affichageGrille.h"
#include "main.h"

void afficherCase (int couleur)
{
	switch (couleur){
		case VIDE:
			printf ("[ ]");
		break;

		case JAUNE:
			printf ("[\e[1;33m#\e[0m]");
		break;

		case ROUGE:
			printf ("[\e[1;31m+\e[0m]");
		break;
	}
}

void affichageGrille (void)
{
	int i,j;

	for (i = 0; i < 6; i ++) {
		for (j = 0; j <7; j ++){
			afficherCase (grille[j][i]);
		}
		printf ("\n");
	}
}