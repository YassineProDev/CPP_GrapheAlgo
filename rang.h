#include <iostream>
#include <vector>
#include "grapheOrienteNV.h"

using namespace std;


class rang
{
public :
    rang(grapheOrienteNV graph);
    void saisie();
    void affichage();

    void empiler (int x, vector<int> &pilch);
    void calculRang();
    void afficherRang();

private:

    grapheOrienteNV graphe;
    vector<int> tabRang;
};
