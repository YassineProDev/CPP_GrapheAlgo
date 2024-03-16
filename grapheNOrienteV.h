#ifndef GRAPHENORIENTEV
#define GRAPHENORIENTEV

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


class grapheNOrienteV
{
public :
    grapheNOrienteV();
    grapheNOrienteV(string nomFichier);
    void construireAdjacence();
    void construireAdjacenceFichier(string nomFichier);
    vector<vector<int>> adjacence;
    vector<vector<int>> matriceCout;

    int nbSommet;
    int nbArc;
};

#endif // GRAPHENORIENTENV
