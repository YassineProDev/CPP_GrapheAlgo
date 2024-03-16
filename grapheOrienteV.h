#ifndef GRAPHEORIENTEV
#define GRAPHEORIENTEV

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


class grapheOrienteV
{
public :
    grapheOrienteV();
    grapheOrienteV(string nomFichier);
    void saisie();
    void saisieFichier(string nomFichier);
    void initialisationMatriceCout(int s);
    void genererMatriceAdjacence();


    vector<int> fs;
    vector<int> aps;

    vector<vector<int>> matriceCout;
    vector<vector<int>> matriceAdjacence;

    int nbSommet;
    int nbArc;
};
#endif // GRAPHEORIENTEV
