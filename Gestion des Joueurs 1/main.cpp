#include "joueur.h"
#include"menu.h"
#include <future>
#include "gestionJoueurs.h"
#define NB_MAX_JOUEURS 20

enum CHOIX_MENU
{
    AJOUTER = 1,
    VISUALISER,
    CHARGER,
    SAUVEGARDER,
    QUITTER
};

int main(int argc, char** argv)
{
    Menu leMenu("Menu.txt");
    int choix;
    Joueur tabJoueurs[NB_MAX_JOUEURS];
    int nbJoueurs = 0;
    string pseudo;
    int score;
    int duree;
    do
    {
        choix = leMenu.AfficherEtAttendreChoix();
        switch (choix)
        {
        case AJOUTER:
        {
            int pos;

            cout << "Pseudo score durée :";
            cin >> pseudo >> score >> duree;

            if (nbJoueurs > 0)
            {
                pos = RechercherJoueur(tabJoueurs, NB_MAX_JOUEURS, pseudo);

                if (pos != -1)
                {
                    tabJoueurs[pos].Actualiser(score, duree);
                }
                else
                {
                    tabJoueurs[nbJoueurs++] = Joueur(pseudo, score, duree);
                }
            }
            else
            {
                tabJoueurs[nbJoueurs++] = Joueur(pseudo, score, duree);
            }
            if (nbJoueurs > 1)
            {
                TrierTableauJoueurs(tabJoueurs, NB_MAX_JOUEURS);
            }

            Menu::EffacerEcran();
            break;
        }
        case VISUALISER:
        {
            cout << '+' << setfill('-') << setw(16) << '+' << setw(12) << '+' << setw(12) << '+' << endl;
            for (int i = 0; i < nbJoueurs; i++)
            {
                tabJoueurs[i].ObtenirInfo(pseudo, score, duree);
                cout << '|' << setfill(' ') << setw(15) << left << pseudo << '|' << setw(11) << score << '|' << setw(11) << duree << '|' << endl;
            }
            cout << '+' << setfill('-') << right << setw(16) << '+' << setw(12) << '+' << setw(12) << '+' << endl;
            break;
        }
        case CHARGER:
        {
            



            break;
        }
        case SAUVEGARDER:




            break;
        }
    }
    while (choix != QUITTER);
    return 0;
}

