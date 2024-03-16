#include <iostream>
#include "grapheNOrienteV.h"

using namespace std;

typedef struct {
    int s; // premi�re extr�mit� de l'ar�te
    int t; // deuxi�me extr�mit� de l�ar�te
    double p; // poids de l�ar�te
} arete;

typedef struct {
    int n; // nombre de sommets du graphe
    int m; //nombre d�ar�tes du graphe arete *a;
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
