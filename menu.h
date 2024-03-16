#include <iostream>
#include <vector>

#include "graphics.h"
#include <math.h>
#include <memory>

#include "rang.h"
#include "pruferCodage.h"
#include "pruferDecodage.h"
#include "tarjan.h"
#include "dijkstra.h"
#include "kruskal.h"
#include "ordonnancement.h"
#include "distance.h"
#include "danzig.h"
#include "interface.h"
#include "interfaceGraphique.h"
#include "interfaceAlphanumérique.h"
#include "interfaceFichier.h"

#include "grapheNOrienteNV.h"
#include "grapheNOrienteV.h"
#include "grapheOrienteNV.h"
#include "grapheOrienteV.h"

using namespace std;


class menu
{
  public :
    menu();
    void accueil();
    void afficherTitre();
    int choixInterface();
    int choixSaisie();

    void algoGrapheNOrienteV(grapheNOrienteV g);
    void algoGrapheNOrienteNV(grapheNOrienteNV g);
    void algoGrapheOrienteNV(grapheOrienteNV g);
    void algoGrapheOrienteV(grapheOrienteV g);

    void modifierGrapheOrienteNV(grapheOrienteNV g);

    std::unique_ptr<interface> creationInterface(int a) const;

  private:

};
