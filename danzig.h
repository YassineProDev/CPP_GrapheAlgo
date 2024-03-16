#ifndef DANZIG
#define DANZIG

#include <iostream>
#include <vector>
#include "grapheOrienteV.h"

using namespace std;


class dantzig
{
public :
    dantzig(grapheOrienteV graph);
    void Dantzig();
private :
   grapheOrienteV graphe;
};

#endif // DANZIG
