#include <iostream>
#include "grapheNOrienteV.h"

using namespace std;

typedef struct {
    int s; // première extrémité de l'arête
    int t; // deuxième extrémité de l’arête
    double p; // poids de l’arête
} arete;

typedef struct {
    int n; // nombre de sommets du graphe
    int m; //nombre d’arêtes du graphe arete *a;
    arete *a; // tableau des aretes
} graphe;


class kruskal
{
public :
    kruskal(grapheNOrienteV graph);
    //void saisie(graphe &g);
    void conversion(graphe &g);
    void affichage(graphe g);
    void trier(graphe &g);
    void affichet(int *a, int n);
    void fusionner(int i, int j, int *prem, int *pilch, int *cfc, int *NbElem);
    void Kruskal(graphe g, graphe &t, int *prem, int *pilch, int *cfc, int *NbElem);
private :
    grapheNOrienteV grapheNOV;

};
