/* affichage.c créé par YVOZ Ludovic et IOPETI Hugo le 11/03/2020 */

#include "affichage.h"

void affichage_brut(int** pl)
{
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

void afficher(int** pl)
{
	for (int k = 0; k < (P_SIZE*2) + 3; ++k)	//Délimite le haut du plateau / (P_SIZE*2) + 3 : pour délimiter tous les caractères et les espaces  + les côtés (3 caractères).
	{
		printf("-");
	}
	
	for (int i = 0; i < P_SIZE; ++i)		//Parcours la 1ère dimension du plateau
	{
		printf("\n");
		printf("| ");
		for (int j = 0; j < P_SIZE ; ++j)		//Parcours la 2ème dimension du plateau + les côtés
		{
			switch ( pl[i][j] )
			{	
				case (0):
					printf("  ");
					break;
					
				case (1):
					printf(". ");
					break;
					
				case (2):
					printf("# ");
					break;
					
				case (F):
					printf("F ");
					break;
					
				case (J):
					printf("J ");
					break;
				default : exit(1); 
			}
		}
		printf("| ");
	}
	
	printf("\n");
	for (int k = 0; k < (P_SIZE*2) + 3; ++k)	//Délimite le bas du plateau / (P_SIZE*2) + 3 : pour délimiter tous les caractères et les espaces  + les côtés (3 caractères).
	{
		printf("-");
	}
	printf("\n");
}
