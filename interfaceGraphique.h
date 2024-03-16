#ifndef INTERFACEGRAPHIQUE_H
#define INTERFACEGRAPHIQUE_H

#include "grapheNOrienteNV.h"
#include "grapheNOrienteV.h"
#include "grapheOrienteNV.h"
#include "grapheOrienteV.h"
#include "graphics.h"
#include "interface.h"
#include <math.h>
#include <memory>
#include <iostream>

using namespace std;

class interfaceGraphique : public interface
{
public:
    interfaceGraphique();

    void drawGraphNONV(vector<vector<int>> adjMatrix)const override;
    void drawGraphNOV(vector<vector<int>> adjMatrix)const override;
    void drawGraphONV(vector<vector<int>> adjMatrix)const override;
    void drawGraphOV(vector<vector<int>> adjMatrix)const override;

private:
};





#endif // INTERFACEGRAPHIQUE_H
