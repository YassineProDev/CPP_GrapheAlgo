#ifndef TARJAN_H_INCLUDED
#define TARJAN_H_INCLUDED
#include "grapheOrienteNV.h"
#include <bits/stdc++.h>
#define NIL -1
using namespace std;
#include <iostream>

class tarjan {

    int V; // Nombre de sommets
    list<int>* adj; // Un tableau dynamique de listes d'adjacence

    void SCCUtil(int u, int disc[], int low[],stack<int>* st, bool stackMember[]);

public:
    tarjan(grapheOrienteNV graph); // Constructeur
    void ajouteArete(int v,
    int w); // Fonction pour ajouter une arête au graphe
    void CFC(); // imprime les composantes fortement connexes

private:
    grapheOrienteNV graphe;

};

#endif // TARJAN_H_INCLUDED
