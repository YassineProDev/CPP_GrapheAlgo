#ifndef GRAPHENORIENTENV
#define GRAPHENORIENTENV

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


class grapheNOrienteNV
{
public :
    grapheNOrienteNV();
    grapheNOrienteNV(string nom_fichier);
    void construireAdjacence();
    void construireAdjacenceFichier(string nom_fichier);
    vector<vector<int>> adjacence;
};

#endif // GRAPHENORIENTENV
