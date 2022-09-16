/**
 * \file fantome.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \brief Définition des fantômes sous forme de structures
 */
 
#include "plateau.h"

/**
 * \struct fantome
 * \typedef fantome_t
 * \brief Définit le fantome (son emplacement sur la plateau et la lettre qui le représente)
 */
struct fantome
{
	int x;
	int y;
	char lettre;
};
typedef struct fantome fantome_t;

/**
 * \fn fantome_t** placer_f(int** pl, int n)
 * \brief Création de n fantômes
 * \param pl Plateau sur lequel on dispose le joueur.
 * \param n Nombre de fantômes.
 * \return \a n nouveau fantômes.
 */
fantome_t** placer_f(int** pl, int n);

/**
 * \fn void deplacer_f(int** pl, fantome_t** fants, int n)
 * \brief Déplace les fantômes
 * \param pl Plateau sur lequel on dispose le joueur.
 * \param fants Les fontômes actuels.
 * \param n Nombre de fantômes.
 * \return Déplacement des fantomes \a fants sur le plateau \a pl aléatoirement.
 */
void deplacer_f(int** pl, fantome_t** fants, int n);
