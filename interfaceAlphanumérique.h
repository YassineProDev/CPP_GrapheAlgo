#ifndef INTERFACEALPHANUMERIQUE_H
#define INTERFACEALPHANUMERIQUE_H

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

class interfaceAlphanumerique : public interface
{
public:
    interfaceAlphanumerique();

    void drawGraphNONV(vector<vector<int>> adjMatrix)const override;
    void drawGraphNOV(vector<vector<int>> adjMatrix)const override;
    void drawGraphONV(vector<vector<int>> adjMatrix)const override;
    void drawGraphOV(vector<vector<int>> adjMatrix)const override;

private:
};





#endif // INTERFACEALPHANUMERIQUE_H
