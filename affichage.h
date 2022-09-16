/**
 * \file affichage.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \brief Définition des fonctions affichant le plateau de jeu.
 */

#include "plateau.h"

/**
 * \fn void affichage_brut(int** pl)
 * \brief Affiche les entiers contenus dans le tableau.
 * \param pl Plateau de jeu actuel.
 * \return Affichage des éléments du plateau \a pl sous forme d'entiers.
 */
void affichage_brut(int** pl);

/**
 * \fn void afficher(int** pl)
 * \brief Affiche le plateau.
 * \param pl Plateau de jeu actuel.
 * \return Affichage du plateau \a pl en ascii art.
 */
void afficher(int** pl);
