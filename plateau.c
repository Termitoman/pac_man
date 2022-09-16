/* plateau.c créé par YVOZ Ludovic et IOPETI Hugo le 05/03/2020 */

#include "plateau.h"

int** creer_plateau()
{
	int** nouveau_plateau = malloc(sizeof(int*)*P_SIZE);
	for (int i = 0; i < P_SIZE; ++i)		//Allocation de la mémoire pour la 2ème dimension du tableau
	{
		nouveau_plateau[i] = malloc(sizeof(int)*P_SIZE);
	}
	for (int i = 0; i < P_SIZE; ++i)		//On remplit le plateau de cases vides
	{
		for (int j = 0; j < P_SIZE; ++j)
		{
			nouveau_plateau[i][j] = 0;
		}
	}
	return nouveau_plateau;
}

int valide(int** pl, int i, int j)
{
	if (i < P_SIZE && j < P_SIZE && i >= 0 && j >= 0 && pl[i][j] != M)
	{
		return 0;
	}
	return -1;
}
