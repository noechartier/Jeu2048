#include "menu.h"
#include <future>

Menu::Menu(const string &_nom) : nom(_nom), longueurMax(0)
{
    string option;

    ifstream leFichier("Menu.txt"); // ouvrir le fichier

    if (!leFichier.is_open())
    {// Si il y a une erreur

        cerr << "Erreur lors de l'ouverture du fichier" << endl; // alors Afficher un message indiquant une erreur de lecture
        nbOptions = 0; // et mettre nbOptions à 0

    }
    else
    {

        int nbLignes = static_cast<int> (count(istreambuf_iterator<char>(leFichier), istreambuf_iterator<char>(), '\n')); // Sinon calculer nbOptions, le nombre d’options dans le fichier
        leFichier.seekg(0, ios::beg);
        nbOptions = nbLignes;
        options = new string[nbLignes]; // allouer dynamiquement le tableau options en fonction de nbOptions

        for (int i = 0; i < nbLignes; i++)
        {// Pour chaque option dans le fichier
            if (leFichier.good())
            {
                getline(leFichier, option);

                options[i] = option; // Lire l’option et l’affecter dans le tableau options
                if (option.size() > longueurMax)
                {// Si la taille de l’option est plus grande que longueurMax
                    longueurMax = option.size(); // alors longueurMax reçoit la taille de l’option

                }//FinSi
            }// FinSi
        }// FinPour
        leFichier.close();
    }// FinSi
}

Menu::~Menu()
{
    delete [] options;

}

void Menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout << endl << "appuyer sur la touche Entrée pour continuer...";
    getline(cin, uneChaine);
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    system("clear");
}

int Menu::AfficherEtAttendreChoix()
{
    int choix;

    cout << "+" << setw(6) << setfill('-') << "+" << setw(longueurMax - 1) << "+" << endl;
    for (int i = 0; i < nbOptions; i++)
    {
        int nbChoix = i + 1;
        cout << right << "| " << setfill(' ') << setw(2) << nbChoix << setw(2) << "  |" << left << setw(longueurMax - 3) << options[i] << " |" << endl;
    }
    cout << right << "+" << setw(6) << setfill('-') << "+" << setw(longueurMax - 1) << "+" << endl;

    cout << "Entrer un nombre entre 1 et " << nbOptions << " : ";

    if (!(cin >> choix))
    {
        cin.clear();
        cout.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        choix = -1;


    }


    return choix;
}

void Menu::EffacerEcran()
{
    system("clear");
}