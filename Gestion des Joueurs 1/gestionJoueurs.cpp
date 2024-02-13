#include "gestionJoueurs.h"

int RechercherJoueur(Joueur * _tab, const int _nb, const string &_pseudo)
{
    int i = -1;

    while (_tab[i] != _pseudo && i < _nb)
        i++;

    if (i == _nb)
    {
        i = -1;
    }

    return i;
}

void TrierTableauJoueurs(Joueur * _tab, const int _nb)
{
    int trie = _nb;
    bool tri = false;
    while (tri == false)
    {
        tri = true;
        for (int i = 0; i < trie-1; i++)
        {
            if (_tab[i] < _tab[i+1])
            {
                Joueur compteur = _tab[i];
                _tab[i] = _tab[i + 1];
                _tab[i + 1] = compteur;
                tri = false;
            }
        }
        trie--;
    }
}
