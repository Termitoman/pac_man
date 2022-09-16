/**
 * \file plateau.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \brief Définition du plateau de jeu (tableau à deux dimensions).
 */
#ifndef P_SIZE
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define P_SIZE 10
#define F 3
#define J 4
#define M 2
#define F_AVANT 5

/**
 * \fn int** creer_plateau()
 * \brief Création d'un plateau vide.
 * \return Plateau vide.
 */
int** creer_plateau();

/**
 * \fn int valide(int** pl, int i, int g)
 * \brief Détermine si une case du plateau donnée est valide.
 * \param pl Plateau de jeu actuel.
 * \param i indice de la 1ère dimension du tableau.
 * \param j indice de la 2ème dimension du tableau.
 * \return 0 si la case est valide.
 */
int valide(int** pl, int i, int j);

#endif
