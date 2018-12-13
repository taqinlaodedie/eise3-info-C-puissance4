#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "affichageGrille.h"
#include "manipulationGrille.h"
#include "jeuPuissance4.h"

#define TRUE  1
#define FALSE 0

bool estCoupGagnant (int choixJoueur);
void analyserFinDePartie(int dernierCoup);

/*retourne 1 si le coup est invalide*/
bool estCoupInvalide (int colonneJouee)
{
	//printf ("%d", colonneJouee);
	if(nbDeJetonsColonne (colonneJouee) >= 6) {
		return (TRUE);
	}
	else {
		return (FALSE);
	}
}

/*demander le joueur a jouer et retourner son choix*/
int jouerCoupPuissance4 (void)
{
	int choixColonne, res;

	if(joueur == JAUNE) {
		printf ("joueur \e[1;33mJAUNE:\e[0m");
	}
	else {
		printf ("joueur \e[1;31mROUGE:\e[0m");
	}

	res = scanf ("%d", &choixColonne);
	/*retourne -1 s'il y a un erreur*/
	if (res == 0) {
		return (-1);	
	}
	else {
		if ((choixColonne >= 1) && (choixColonne <= 7)) {
			choixColonne --;
			if ((estCoupInvalide (choixColonne)) == TRUE) {
				printf("Colonne invalide\n");
				jouerCoupPuissance4();
			}
			else {
				return (choixColonne);
			}
		}
		else {
			printf ("La valeur doit etre entre 1 et 7\n");
			jouerCoupPuissance4 ();
		}
	}
	
}

/*retourne true si le jeu est fini, false sinon*/
int jouerPartiePuissance4 (void)
{
	int i, j, choix;
	bool grillePleinne = TRUE;

	/*verifier si la grille est pleine*/
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 6; j++) {
			if (grille[i][j] == VIDE) {
				grillePleinne = FALSE;
			}
		}
	}
	if (grillePleinne == TRUE) {
		/*retourne 1 si la grille est pleine*/
		printf ("pleine\n");
		return (1);
	}
	else if (grillePleinne == FALSE){
		/*retourne 1 s'il y a un gagnant, 0 sinon*/
		choix = jouerCoupPuissance4 ();
		if (choix == (-1)) {//fonction jouerCoupPuissance4 retourne TRUE quand il y a un erreur
			printf ("Erreur en entree, fin du jeu\n");
			return (TRUE);
		}

		analyserFinDePartie (choix);
		if(estCoupGagnant (choix) == FALSE) {	
			return (FALSE);
		}
		else {
			switch (joueur) {
				case JAUNE : 
					printf ("Joueur \e[1;33mJAUNE\e[0m gagne\n");
				break;

				case ROUGE :
					printf ("Joueur \e[1;31mROUGE\e[0m gagne\n");
				break;
			}
			return (TRUE);
		}
	}
}

/*verifier si le dernier coup est gagnant, sioui, retourne 1*/
bool estCoupGagnant (int choixJoueur)
{
	int positionY = 0;//trouver la position Y du jeton
	int i = 0, j,p,q;
	int nbJeton;//nombre de jetons en meme couleur

	while (grille[choixJoueur][i] == VIDE) {
		i ++;
	}
	positionY = i;

	/*recherche horizontale*/
	for (i = 0; i <= 3; i ++) {
		nbJeton = 0;
		for (j = i; j < i + 4; j ++) {
			if (grille[j][positionY] == grille[choixJoueur][positionY]) {
				nbJeton ++;
			}
			else {
				break;
			}
		}
		if (nbJeton >= 4) {
			return (TRUE);
		}
	}

	/*recherche verticale*/
	for (i = 0; i <= 2; i ++) {
		nbJeton = 0;
		for (j = i; j < i + 4; j ++) {
			if (grille[choixJoueur][j] == grille[choixJoueur][positionY]) {
				nbJeton ++;
			}
			else {
				break;
			}
		}
		if (nbJeton >= 4) {
			return (TRUE);
		}
	}

	/*recherche vers haut vers gauche, trouver une plus grande rectangle*/
	for (i = choixJoueur, j = positionY; (i > 0) && (j > 0); i --, j --) {
		/*le but de la boucle est de trouver des bonnes valeurs pour i et j donc on ne fait rien dedans*/
	}
	/*chercher de la position trouvee vers le bas le droit s'il y a 4 jetons de la meme couleur*/
	for (; (i <= 4) && (j <= 3); i ++, j ++) {
		nbJeton = 0;
		for (p = i, q = j; p < i + 4; p ++, q++) {
			if (grille [p][q] == grille [choixJoueur][positionY]) {
				nbJeton ++;
			}
			else {
				break;
			}
			if (nbJeton >= 4) {
				return (TRUE);
			}
		}
	}

	/*meme facon pour trouver une plus grande rectangle au bas au gauche*/
	for (i = choixJoueur, j = positionY; (i > 0) && (j < 6); i --, j ++) {
		/*ne fait rien*/
	}
	/*recherche vers haut vers doite*/
	for (; (i <= 4) && (j >= 3); i ++, j --) {
		nbJeton = 0;
		for (p = i, q = j; p < i + 4; p ++, q --) {
			if (grille [p][q] == grille [choixJoueur][positionY]) {
				nbJeton ++;
			}
			else {
				break;
			}
			if (nbJeton >= 4) {
				return (TRUE);
			}
		}
	}

	/*retourne fause si les trois verifications n'ont pas un vrai*/
	return (FALSE);
}

/*afficher l'ecran*/
void analyserFinDePartie (int dernierCoup)
{
	ajouterJeton (dernierCoup);
	affichageGrille ();
}