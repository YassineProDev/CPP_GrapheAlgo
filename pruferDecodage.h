#include <iostream>
#include <vector>
#include "grapheNOrienteNV.h"

using namespace std;


class pruferDecodage
{
public :
    pruferDecodage();

    void saisieDecodage();
    void decodage();

    vector<int> codePrufer;
    vector<vector<int>> adjacence;
};

