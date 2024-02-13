#include "joueur.h"

Joueur::Joueur() : duree(0), score(0)
{
    pseudo.clear();
}

Joueur::Joueur(const string _pseudo, const int _score, const int _duree) : pseudo(_pseudo), score(_score), duree(_duree)
{

}

void Joueur::Actualiser(const int _nouveauScore, const int _duree)
{
    if (score < _nouveauScore)
    {
        score = _nouveauScore;
    }
    duree += _duree;
}

void Joueur::ObtenirInfo(string &_pseudo, int &_score, int &_duree)
{
    _pseudo = pseudo;
    _score = score;
    _duree = duree;
}

bool Joueur::operator<(const Joueur &_autre)const
{
    bool retour = false;
    if (score < _autre.score)
    {
        retour = true;
    }
    return retour;
}

bool Joueur::operator!=(const string _pseudo) const
{
    bool retour = false;
    if (pseudo != _pseudo)
    {
        retour = true;
    }
    return retour;
}

//ostream & operator<<(ostream &_flux, const Joueur &_joueur)
//{
//    return _flux << _joueur.pseudo << ' ' << _joueur.score << ' ' << _joueur.duree << ' ' << endl;
//}
//
//istream & operator>>(istream &_flux, Joueur &_joueur)
//{
//    return _flux >> _joueur.pseudo >> _joueur.score >> _joueur.duree;
//}