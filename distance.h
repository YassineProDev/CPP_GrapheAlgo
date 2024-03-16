#ifndef DISTANCES
#define DISTANCES

#include <iostream>
#include <vector>
#include "grapheOrienteNV.h"
using namespace std;


class distances
{
public :
    distances(grapheOrienteNV graph);
    void desc_large1(int r);
private :

    grapheOrienteNV graphe;
    vector<int> dist;
};

#endif // DISTANCES
