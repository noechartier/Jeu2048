#ifndef MENU_H
#define MENU_H
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class Menu
{
public:
    Menu(const string &_nom);
    ~Menu();
    int AfficherEtAttendreChoix();
    static void AttendreAppuiTouche();
    static void EffacerEcran();
private:
    string nom;
    string* options;
    int nbOptions;
    int longueurMax;
};

#endif /* MENU_H */

