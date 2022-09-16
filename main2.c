//main2.c créé par YVOZ Ludovic et IOPETI Hugo le 28/03/2020
//Toutes les modifications par rapport au fichier main.c sont marquées par un commentaire.

#include "plateau.h"
#include "affichage.h"
#include "fantome.h"
#include "joueur.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));

    printf("Bienvenue dans PACMAN : pêche illégale !\n"); //printf modifié pour aller avec le nouveau thème du jeu.

    int ** plateau = creer_plateau();

    int nb_rand_1, nb_rand_2;
    for (int i = 0; i < P_SIZE * 1.5; ++i)
    {
        nb_rand_1 = rand()%(P_SIZE);
        nb_rand_2 = rand()%(P_SIZE);
        plateau[nb_rand_1][nb_rand_2] = M;
    }

    joueur_t* joueur = placer_j(plateau);

    printf("Combien de krakens sont à votre poursuite ? "); //printf modifié pour aller avec le nouveau thème du jeu.
    int nb_fants;
    scanf("%d",&nb_fants);
    getchar();

    fantome_t** fants = placer_f(plateau, nb_fants);

    int nb_pac_gommes = 0;
    for (int i = 0; i < P_SIZE; ++i)
    {
        for (int j = 0; j < P_SIZE; ++j)
        {
            if (plateau[i][j] == 0)
                {
                    plateau[i][j] = 1;
                    ++nb_pac_gommes;
                }
        }
    }

    int score = 0;

    while (nb_pac_gommes != 0)
    {
        afficher(plateau);
        printf("Vous avez pêché %d poissons\n",
            score);     //printf modifié pour aller avec le nouveau thème du jeu.

        deplacer_j(plateau, joueur);

        if (plateau[joueur->x][joueur->y] == 1)
        {
            ++score;
        }

        update_j(plateau, joueur);

        deplacer_f(plateau, fants, nb_fants);

        if (plateau[joueur->x][joueur->y] == F)
        {
            printf("Vous avez perdu ! Vous aviez %d poissons avant qu'ils ne soient relachés par le kraken !\n",score); //printf modifié pour aller avec le nouveau thème du jeu.
            return EXIT_FAILURE;
        }

        nb_pac_gommes = 0;
        for (int i = 0; i < P_SIZE; ++i)
        {
            for (int j = 0; j < P_SIZE; ++j)
            {
                if (plateau[i][j] == 1)
                {
                    ++nb_pac_gommes;
                }
            }
        }

        system("clear");    //On utilise une commande bash pour effacer ce qu'il y a d'écrit dans le terminal au lieu de just créer un espace pour que l'on ne vois pas ce qu'il y avait d'écrit avant.
    }
    score += P_SIZE;
    printf("Vous avez gagné ! Vous avez pêché tous les poissons de la zone (%d) ! Bravo l'écologie !\n",score); //printf modifié pour aller avec le nouveau thème du jeu.
    return EXIT_SUCCESS;
}