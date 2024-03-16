#ifndef GRAPHEORIENTENV
#define GRAPHEORIENTENV

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


class grapheOrienteNV
{
public :
    grapheOrienteNV();
    grapheOrienteNV(string nomFichier);
    void saisie();
    void saisieFichier(string nomFichier);
    void genererMatriceAdjacence();
    void genererFsAps();

    void ajouterSommet();
    void ajouterArete();
    void supprimerArete();



    vector<int> fs;
    vector<int> aps;

    vector<vector<int>> matriceAdjacence;

    int nbSommet;
    int nbArc;
};

#endif // GRAPHEORIENTENV
