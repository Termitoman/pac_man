/* joueur.c créé par YVOZ Ludovic et IOPETI Hugo le 11/03/2020 */

#include "joueur.h"


joueur_t* placer_j(int** pl)
{
	joueur_t* jou_actu ; 
	jou_actu = malloc(sizeof(joueur_t));

	jou_actu->x = rand()%(P_SIZE);
	jou_actu->y = rand()%(P_SIZE);
	
	while ( valide( pl,jou_actu->x,jou_actu->y ) == -1 ) //Tant que le joueur apparait sur un mur on recommence
	{
		jou_actu->x = rand()%(P_SIZE);
		jou_actu->y = rand()%(P_SIZE);
	}
	
	jou_actu->lettre = 'J';
	
	pl[jou_actu->x][jou_actu->y] = J;
	
	return jou_actu;
}

void deplacer_j(int** pl, joueur_t* jou)
{
	pl[jou->x][jou->y] = 0;

	int tempo_x = jou->x;
	int tempo_y = jou->y;

	char deplacement;
	printf("Où voulez-vous vous déplacer (z, q, s, d), vous pouvez aussi arrêter la partie avec f ");
	scanf("%c", &deplacement);	//On suppose que l'utilisateur ne rentrerien d'autre que ce qui est demandé !
	getchar();
	
	switch ( deplacement )
	{
		case ('z'):
			if (tempo_x != 0 && valide(pl,tempo_x - 1,tempo_y) == 0 ) //Teste si le prochain déplacement est valide avant de le faire.
			{
				--tempo_x;
			}
			break;
		
		case ('q'):
			if (tempo_y != 0 && valide(pl,tempo_x,tempo_y - 1) == 0 )
			{
				--tempo_y;
			}
			break;
		
		case ('s'):
			if (tempo_x != P_SIZE && valide(pl,tempo_x + 1,tempo_y) == 0 )
			{
				++tempo_x;
			}
			break;
			
		case ('d'):
			if (tempo_y != P_SIZE && valide(pl,tempo_x,tempo_y + 1) == 0 )
			{
				++tempo_y;
			}
			break;

		case ('f'):
			printf("La partie est terminée !\n");
			exit(EXIT_SUCCESS);
			break;
		default : 
			printf("Erreur : vous n'avez pas rentré un caractère valide (surement un enter).\n");
			exit(EXIT_FAILURE); 
	}

	jou->x = tempo_x;
	jou->y = tempo_y;

}

void update_j(int** pl, joueur_t* jou)
{
	pl[jou->x][jou->y] = J ;
}
				
