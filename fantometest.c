/* fantometest.c créé par YVOZ Ludovic et IOPETI Hugo le 13/03/2020 */

#include "fantome.h"
#include "affichage.h"

void test_placer_f()
{
	int** plato = creer_plateau();
	
	int n;
	printf("Combien de fantômes voulez-vous créer : ");
	scanf("%d",&n);
	
	placer_f(plato, n);
	
	affichage_brut(plato);
}

void test_deplacer_f_param(int**pl , fantome_t** fants, int n) //Nombre de fantome pour parcourir le tableau (Ajouté de l'énoncé)
{
	for (int i = 0; i < n; ++i)
	{
		printf("Les coordonnées du fantôme %d sont les suivantes : x = %d , y = %d\n",
		i+1,fants[i]->x , fants[i]->y);
	}
	deplacer_f(pl, fants, n);
		
	for (int i = 0; i < n; ++i)
	{
		printf("Les coordonnées du fantôme %d sont les suivantes : x = %d , y = %d\n",
		i+1,fants[i]->x , fants[i]->y);
	}
}
void test_deplacer_f()
{
	int** pl = creer_plateau();
	
	int n;
	printf("Combien de fantômes voulez-vous créer : ");
	scanf("%d",&n);
	
	fantome_t** fants = placer_f(pl, n);
	
	test_deplacer_f_param(pl,fants,n);
	
	for (int i = 0; i < n; ++i)
	{
		fants[i]->x = P_SIZE - (P_SIZE / 2);		//Fantôme placé dans une autre case qui varie selon la taille du plateau et donc ne dépasse pas
		fants[i]->y = P_SIZE - (P_SIZE / 2);
	}
	test_deplacer_f_param(pl,fants,n);
	
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	test_placer_f();
	test_deplacer_f();
	return EXIT_SUCCESS;
}

/*Résultat du test :
Combien de fantômes voulez-vous créer : 4 
Voici le plateau :
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 
Combien de fantômes voulez-vous créer : 2
Les coordonnées du fantôme 1 sont les suivantes : x = 0 , y = 5
Les coordonnées du fantôme 2 sont les suivantes : x = 3 , y = 9
Les coordonnées du fantôme 1 sont les suivantes : x = 0 , y = 4
Les coordonnées du fantôme 2 sont les suivantes : x = 2 , y = 9
Les coordonnées du fantôme 1 sont les suivantes : x = 5 , y = 5
Les coordonnées du fantôme 2 sont les suivantes : x = 5 , y = 5
Les coordonnées du fantôme 1 sont les suivantes : x = 4 , y = 5
Les coordonnées du fantôme 2 sont les suivantes : x = 5 , y = 5
*/