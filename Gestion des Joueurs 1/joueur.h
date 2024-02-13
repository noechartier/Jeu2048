#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
using namespace std;

class Joueur
{
public:
    Joueur();
    Joueur(const string _pseudo, const int _score = 0, const int duree = 0);
    void Actualiser(const int _nouveauScore, const int _duree);
    void ObtenirInfo(string &_pseudo, int &_score, int &_duree);
    bool operator<(const Joueur &_autre)const;
    bool operator!=(const string _pseudo) const;
private:
    string pseudo;
    int score;
    int duree;
};

#endif /* JOUEUR_H */

