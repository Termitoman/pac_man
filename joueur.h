/**
 * \file joueur.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \brief Définition du joueur (structure).
 */

#include "plateau.h"
/**
 * \struct joueur
 * \typedef joueur_t
 * \brief Définit le joueur (son emplacement sur la plateau et la lettre qui le représente)
 */
struct joueur
{
	int x;
	int y;
	char lettre;
};
typedef struct joueur joueur_t;

/**
 * \fn joueur_t* placer_j(int** pl)
 * \brief Création du joueur
 * \param pl Plateau sur lequel on dispose le joueur.
 * \return un nouveau joueur.
 */
joueur_t* placer_j(int** pl);

/**
 * \fn void deplacer_j(int** pl, joueur_t* jou)
 * \brief Déplace le joueur
 * \param pl Plateau sur lequel on dispose le joueur.
 * \param jou Le joueur actuel.
 * \return Déplacement du joueur \a jou sur le plateau \a pl selon le choix de l'utilisateur.
 */
void deplacer_j(int** pl, joueur_t* jou);

/**
 * \fn void update_j(int** pl, joueur_t* jou)
 * \brief Met à jour l'emplacement du joueur.
 * \param pl Plateau sur lequel on dispose le joueur.
 * \param jou Le joueur actuel.
 * \return Mise à jour de l'emplacement du joueur \a jou selon le deplacement effectué précédemment.
 */
void update_j(int** pl, joueur_t* jou);
