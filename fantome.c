/* fantome.h créé par YVOZ Ludovic et IOPETI Hugo le 05/03/2020 */

#include "fantome.h"

fantome_t** placer_f(int** pl, int n)
{
	fantome_t** fants_actu; //fantome_t** = tableau de structure
	
	fants_actu = malloc(sizeof(fantome_t*)*n);
	for (int i = 0; i < n; ++i)
	{
		fants_actu[i] = malloc(sizeof(fantome_t));
	}


	for (int i = 0; i < n; ++i)
	{
		fants_actu[i]->x = rand()%(P_SIZE);
		fants_actu[i]->y = rand()%(P_SIZE);
		
		while ( valide( pl,fants_actu[i]->x,fants_actu[i]->y ) == -1 || pl[fants_actu[i]->x][fants_actu[i]->y] == J || pl[fants_actu[i]->x][fants_actu[i]->y] == F) //Tant que les fantômes apparaissent sur un mur ou sur le joueur ou sur un fantôme créé auparavant, on recommence.
		{
			fants_actu[i]->x = rand()%(P_SIZE);
			fants_actu[i]->y = rand()%(P_SIZE);
		}
		
		fants_actu[i]->lettre = 'F';
		
		pl[fants_actu[i]->x][fants_actu[i]->y] = F;		//Existe sur le plateau
	}
	return fants_actu;
}

void deplacer_f(int** pl, fantome_t** fants, int n)
{
	for (int i = 0; i < n; ++i)	//On efface les fantômes du plateau avant de les déplacer autre part et on met une autre constante pour empêcher aux autres fantômes de se déplacer (erreur de type 2 fantômes sur une case).
	{
		if (pl[fants[i]->x][fants[i]->y] != J)	//Si le joueur suit le fantôme, il ne disparaitra pas.
		{
			pl[fants[i]->x][fants[i]->y] = F_AVANT;
		}
	}

	int tempo_x, tempo_y;
	for (int i = 0; i < n; ++i)
	{
		tempo_x = fants[i]->x;
		tempo_y = fants[i]->y;

		int case_d = rand()%(3); //Choisis une direction au hasard entre 1 et 4	
		
		switch (case_d)
		{
			case (0): //Haut
				if (tempo_x != 0 && valide(pl,tempo_x - 1,tempo_y) == 0 && pl[tempo_x - 1][tempo_y] != F && pl[tempo_x - 1][tempo_y] != F_AVANT) //Teste si le prochain déplacement est valide avant de le faire.
				{
					--tempo_x;
				}
				
				break;
				
			case (1) : //Gauche
				if (tempo_y != 0 && valide(pl,tempo_x,tempo_y - 1) == 0 && pl[tempo_x][tempo_y - 1] != F && pl[tempo_x][tempo_y - 1] != F_AVANT)
				{
					--tempo_y;
				}
				
				break;
			
			case (2) : //Bas
				if (tempo_x != P_SIZE && valide(pl,tempo_x + 1,tempo_y) == 0 && pl[tempo_x + 1][tempo_y] != F && pl[tempo_x + 1][tempo_y] != F_AVANT)
				{	
					++tempo_x;
				}
			
				break;
				
			case (3) : //Droite
				if (tempo_y != P_SIZE && valide(pl,tempo_x,tempo_y + 1) == 0 && pl[tempo_x][tempo_y + 1] != F && pl[tempo_x][tempo_y + 1] != F_AVANT)
				{
					++tempo_y;
				}
				
				break;
			default : 
				printf("Erreur : case_d = %d",case_d);
				exit(EXIT_FAILURE);	//Quitte la fonction et fait un return(1) dans le main ce qui équivaut à un return(EXIT_FAILURE)
		}
		pl[tempo_x][tempo_y] = F ;

		fants[i]->x = tempo_x;
		fants[i]->y = tempo_y;
	}
	
	for (int i = 0; i < P_SIZE; ++i) //On parcours le plateau pour enlever les traces de déplacement des fantômes.
	{
		for (int j = 0; j < P_SIZE; ++j)
		{
			if (pl[i][j] == F_AVANT)
			{
				pl[i][j] = 0;
			}
		}
	}
}
