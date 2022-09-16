//main.c créé par YVOZ Ludovic et IOPETI Hugo le 24/03/2020

#include "plateau.h"
#include "affichage.h"
#include "fantome.h"
#include "joueur.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));

    printf("Bienvenue dans PACMAN 2 : Le retour !\n");

    //Création du plateau de jeu initial avec des murs
    int ** plateau = creer_plateau();

    int nb_rand_1, nb_rand_2;
    for (int i = 0; i < P_SIZE * 1.5; ++i)      //Placement des murs de manière aléatoire sur le plateau
    {
        nb_rand_1 = rand()%(P_SIZE);
        nb_rand_2 = rand()%(P_SIZE);
        plateau[nb_rand_1][nb_rand_2] = M;
    }

    //Placement du joueur et des fantômes
    joueur_t* joueur = placer_j(plateau);

    printf("Combien de fantômes sont à votre poursuite ? ");
    int nb_fants;
    scanf("%d",&nb_fants);
    getchar();		//Permet d'utiliser deux scanf à la suite.

    fantome_t** fants = placer_f(plateau, nb_fants);

    //Placement des pac-gommes
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

    while (nb_pac_gommes != 0)     //Boucle de déroulement du jeu
    {
        afficher(plateau);
        printf("Votre score est : %d\n",
            score);

        deplacer_j(plateau, joueur);

        if (plateau[joueur->x][joueur->y] == 1) //On regarde si le joueur se déplace sur une pac-gomme et on augmente le score en conséquence.
        {
            ++score;
        }

        update_j(plateau, joueur);

        deplacer_f(plateau, fants, nb_fants);

        if (plateau[joueur->x][joueur->y] == F)
        {
            printf("Vous avez perdu ! Votre score est de %d\n",score);
            return EXIT_FAILURE;
        }

        //On vérifie si le jeu est terminé
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

        printf("\033[H\033[J");
    }
    score += P_SIZE;    //Jeu gagné par le joueur donc bonus de score
    printf("Vous avez gagné ! Votre score est de : %d (+ %d points car vous avez gagné !)\n",score,P_SIZE);
    return EXIT_SUCCESS;
}