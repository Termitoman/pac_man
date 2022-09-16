/* joueur.c créé par YVOZ Ludovic et IOPETI Hugo le 11/03/2020 */

#include "affichage.h"

void test_affichage_brut()
{
	int** plato = creer_plateau();
	
	affichage_brut(plato);
	
	plato[P_SIZE - 1][P_SIZE - 1] = 1;
	plato[P_SIZE / 2][P_SIZE / 2] = 2;
	plato[P_SIZE / 3][P_SIZE / 5] = F;
	plato[P_SIZE / 10][P_SIZE / 4] = J;
	
	affichage_brut(plato);
}

void test_afficher()
{
	int** plato = creer_plateau();
	
	afficher(plato);
	
	plato[P_SIZE - 1][P_SIZE - 1] = 1;
	plato[P_SIZE / 2][P_SIZE / 2] = 2;
	plato[P_SIZE / 3][P_SIZE / 5] = F;
	plato[P_SIZE / 10][P_SIZE / 4] = J;
	
	afficher(plato);
}

int main(int argc,char* argv[])
{
	test_affichage_brut();
	test_afficher();
	return EXIT_SUCCESS;
}

/*Résultat du test :
Voici le plateau :
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
Voici le plateau :
0 0 0 0 0 0 0 0 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 
-----------------------
|                     | 
|                     | 
|                     | 
|                     | 
|                     | 
|                     | 
|                     | 
|                     | 
|                     | 
|                     | 
-----------------------
-----------------------
|                     | 
|     J               | 
|                     | 
|     F               | 
|                     | 
|           #         | 
|                     | 
|                     | 
|                     | 
|                   . | 
-----------------------
*/