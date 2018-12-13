#include <stdio.h>
#include "affichageGrille.h"
#include "main.h"

int demanderCouleurDeLaCaseXY (int absVue, int ordVue)
{
	return (grille[absVue][ordVue]);
}

int nbDeJetonsColonne (int numColonne)
{
	int j, nbJeton, num;

	//printf ("%d", numColonne);
	nbJeton = 0;
	for (j = 5; j >= 0; j --) {
		num = grille[numColonne][j];
		if (num != VIDE) {
			nbJeton ++;
		}
	}

	return (nbJeton);
}

void ajouterJeton (int choixJoueur)
{
	int i = 0;
	
	/*trouver la case qu'il faut modifier*/
	for (i = 0; i < 6; i ++){
		if (grille[choixJoueur][i] == VIDE) {
			continue;
		}
		else {
			break;
		}
	}
	grille[choixJoueur][i - 1] = joueur;
}