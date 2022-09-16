/* joueurtest.c créé par YVOZ Ludovic et IOPETI Hugo le 11/03/2020 */

#include "joueur.h"
#include "affichage.h"

void test_placer_j()
{
	int** plato = creer_plateau();
	
	placer_j(plato);
	
	affichage_brut(plato);
}

void test_deplacer_j_param(int** pl , joueur_t* jou)
{
	printf("Les coordonnées sont les suivantes : x = %d , y = %d\n",
		   jou->x , jou->y);
	
	deplacer_j(pl , jou);
	
	printf("Les coordonnées sont les suivantes : x = %d , y = %d\n",
		   jou->x , jou->y);
}

void test_deplacer_j()
{
	int** pl = creer_plateau();
	joueur_t* jou = placer_j(pl);
	
	test_deplacer_j_param(pl,jou);
	
	jou->x = P_SIZE / 2;		//Joueur placé dans une autre case qui varie selon la taille du plateau et donc ne dépasse pas
	jou->y = P_SIZE / 2;
	
	test_deplacer_j_param(pl,jou);

	jou->x = P_SIZE / 20;		//Joueur placé dans une autre case qui varie selon la taille du plateau et donc ne dépasse pas
	jou->y = P_SIZE / 6;
	
	test_deplacer_j_param(pl,jou);
}

void test_update_j_param(int** pl, joueur_t* jou)
{
	affichage_brut(pl);
	
	update_j(pl,jou);
	
	affichage_brut(pl);
}

void test_update_j()
{
	int** pl = creer_plateau();
	joueur_t* jou = placer_j(pl);
	
	jou->x = P_SIZE - (P_SIZE / 2);		//On modifie les coordonnées selon la taille du plateau pour que ça ne dépasse pas
	jou->y = P_SIZE - (P_SIZE / 2);
	
	test_update_j_param(pl,jou);

}

int main (int argc, char* argv[])
{
	srand(time(NULL));
	
	test_placer_j();
	test_deplacer_j();
	test_update_j();
	
	return EXIT_SUCCESS;
}

/*Résultat du test :
Voici le plateau :
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
Les coordonnées sont les suivantes : x = 9 , y = 4
Où voulez-vous vous déplacer (z, q, s, d), vous pouvez aussi arrêter la partie avec f q
Les coordonnées sont les suivantes : x = 9 , y = 3
Les coordonnées sont les suivantes : x = 5 , y = 5
Où voulez-vous vous déplacer (z, q, s, d), vous pouvez aussi arrêter la partie avec f z
Les coordonnées sont les suivantes : x = 4 , y = 5
Les coordonnées sont les suivantes : x = 0 , y = 1
Où voulez-vous vous déplacer (z, q, s, d), vous pouvez aussi arrêter la partie avec f q
Les coordonnées sont les suivantes : x = 0 , y = 0
Voici le plateau :
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
Voici le plateau :
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
*/