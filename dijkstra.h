#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED
#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include "grapheOrienteV.h"
using namespace std;


// Structure de donn�es pour stocker une ar�te de graphe
struct Arete {
    int source, dest, poid;
};

// Structure de donn�es pour stocker un n�ud de heap
struct Sommet {
    int numero, poid;
};


// Objet de comparaison � utiliser pour ordonner le heap
struct comp
{
    bool operator()(const Sommet &lhs, const Sommet &rhs) const {
        return lhs.poid > rhs.poid;
    }
};

class dijkstra {

public:

 dijkstra(grapheOrienteV graph);
 void afficheChemin(vector<int> const &prec, int i, int source);
 void CheminPlusCourt(int source, int n);
 vector<vector<Arete>> adjList;
 void conversion(vector<Arete>& aretes);

private:
    grapheOrienteV graphe;


};


#endif // DIJKSTRA_H_INCLUDED
