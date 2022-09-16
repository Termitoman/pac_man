// affichage2.c créé par YVOZ Ludovic et IOPETI Hugo le 28/03/2020 
//Toutes les modifications par rapport au fichier affichage.c sont marquées par un commentaire.

#include "affichage.h"

void affichage_brut(int** pl)   //On ne change pas par rapport à la fonction dans afficher.c
{
	printf("Voici le plateau :\n");
	
	for (int i = 0; i < P_SIZE; ++i)
	{
		for (int j = 0; j < P_SIZE; ++j)
		{
			printf("%d ",
				   pl[i][j]);
		}
	}
	printf("\n");
}

void afficher(int** pl)
{
	for (int k = 0; k < (P_SIZE*2) + 3; ++k)
	{
		printf("\033[44;01m\033[32;01m≈\033[00m");     //Fait apparaître le mur du haut sous forme de corail vert.
	}
	
	for (int i = 0; i < P_SIZE; ++i)
	{
		printf("\n");
		printf("\033[44;01m\033[32;01m| \033[00m");     //Fait apparaître le mur du côté gauche sous forme de corail vert.
		for (int j = 0; j < P_SIZE ; ++j)
		{
			switch ( pl[i][j] )
			{	
				case (0):
					printf("\033[44;01m  \033[00m");    //Fait apparaitre le vide comme si on se trouvais au fond de l'océan.
					break;
					
				case (1):
					printf("\033[44;01m\033[37;01m. \033[00m"); //Fait apparaitre les pacgommes comme des petits poissons beiges (représentés par des points pour ne pas surcharger).
					break;
					
				case (2):
					printf("\033[44;01m🌀\033[00m"); //Fait apparaitre les murs intérieurs comme des typhons.
					break;
					
				case (F):
					printf("\033[44;01m\033[35;01m🐙\033[00m"); //Fait apparaitre les fantomes comme des krakens.
					break;
					
				case (J):
					printf("\033[44;01m\033[33;01m🛥 \033[00m");    //Fait apparaitre le joueur comme un bateau de pecheur.
					break;
				default : exit(1); 
			}
		}
		printf("\033[44;01m\033[32;01m|\033[00m");      //Fait apparaître le mur de droite sous forme de corail vert.
	}
	
	printf("\n");
	for (int k = 0; k < (P_SIZE*2) + 3; ++k)
	{
		printf("\033[44;01m\033[32;01m≈\033[00m");      //Fait apparaître le mur du bas sous forme de corail vert.
	}
	printf("\n");
}
