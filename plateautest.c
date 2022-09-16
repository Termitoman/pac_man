/* plateautest.c créé par YVOZ Ludovic et IOPETI Hugo le 05/03/2020 */

#include "plateau.h"

//Procédure qui teste la fonction creer_plateau
void test_creer_plateau()
{
	int ** pl ; 
	pl = creer_plateau();
	
	//affichage du plateau sans utiliser le module affichage
	printf("Voici le plateau :\n");
	
	for (int i = 0; i < P_SIZE; ++i)		//Parcours la 1ère dimension du plateau
	{
		for (int j = 0; j < P_SIZE; ++j)		//Parcours la 2ème dimension du plateau
		{
			printf("%d ",
				pl[i][j]);
		}
	}
	printf("\n");
}

//Procédure qui teste la fonction valide
void test_param_valide(int** pl, int i, int j)
{
	if (valide(pl,i,j) == 0)
	{
		printf("La case est valide !\n");
	}
	else
	{
		printf("La case n'est pas valide !\n");
	}
}

//Procédure qui teste la fonction valide avec des paramètres différents
void test_valide()
{
	int ** pl ; 
	pl = creer_plateau();
	
	//Remplissage de 2 cases du tableau
	
	pl[0][0] = 2;
	pl[1][1] = 1;
	
	test_param_valide(pl,0,0);	//On teste la fonction avec une case pas valide (mur)
	test_param_valide(pl,1,1);	//On teste la fonction avec une case valide
	test_param_valide(pl,69,420); //On teste la fonction avec une case pas valide (hors tableau)
}

int main (int argc ,char* argv[])
{
	test_creer_plateau();
	test_valide();
	return EXIT_SUCCESS;
}

/*Résultat du test :
Voici le plateau :
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
La case n'est pas valide !
La case est valide !
La case n'est pas valide !
*/
