#include "interfaceAlphanumérique.h"
#include "grapheNOrienteNV.h"
#include "grapheNOrienteV.h"
#include "grapheOrienteNV.h"
#include "grapheOrienteV.h"

interfaceAlphanumerique::interfaceAlphanumerique()

{

}

void interfaceAlphanumerique::drawGraphNONV(vector<vector<int>> adjMatrix) const  {
    int numNodes = adjMatrix.size() - 1; // On ignore la première ligne et la première colonne
    string affichage = "\nAffichage alphanumerique : \n";
    string graphString = affichage+"  ";

    // Ajouter les nœuds
    for(int i = 1; i <= numNodes; i++) {
        graphString += to_string(i) + " ";
    }
    graphString += "\n";

    // Ajouter les arêtes
    for(int i = 1; i <= numNodes; i++) {
        graphString += to_string(i) + " ";
        for(int j = 1; j <= numNodes; j++) {
            graphString += (adjMatrix[i][j] == 1) ? "-" : " ";
            graphString += " ";
        }
        graphString += "\n";
    }

    cout<<graphString;
}
void interfaceAlphanumerique::drawGraphNOV(vector<vector<int>> adjMatrix) const  {
    int numNodes = adjMatrix.size() - 1; // exclure la première ligne et la première colonne
    string affichage = "\nAffichage alphanumerique : \n";
    string graphString = affichage;

    // Ajouter les nœuds
    graphString += "Noeuds : ";
    for(int i = 1; i <= numNodes; i++) {
        graphString += to_string(i) + " ";
    }
    graphString += "\n";

    // Ajouter les arêtes
    graphString += "Aretes : \n";
    for(int i = 1; i <= numNodes; i++) {
        for(int j = 1; j <= numNodes; j++) {
            if (adjMatrix[i][j] != -1 && i != j) {
                graphString += "(" + to_string(i) + ", " + to_string(j) + ", " + to_string(adjMatrix[i][j]) + ") ";
            }
        }
        graphString += "\n";
    }

    cout << graphString;
}
void interfaceAlphanumerique::drawGraphOV(vector<vector<int>> adjMatrix) const  {
    int numNodes = adjMatrix.size() - 1; // On ignore la première ligne et la première colonne
    string affichage = "\nAffichage alphanumerique : \n";
    string graphString = affichage + "  ";

    // Ajouter les nœuds
    for(int i = 1; i <= numNodes; i++) {
        graphString += to_string(i) + " ";
    }
    graphString += "\n";

    // Ajouter les arêtes
    for(int i = 1; i <= numNodes; i++) {
        graphString += to_string(i) + " ";
        for(int j = 1; j <= numNodes; j++) {
            if (adjMatrix[i][j] > 0) {
                graphString += "1 ";
            } else {
                graphString += to_string(adjMatrix[i][j]) + " ";
            }
        }
        graphString += "\n";
    }

    cout << graphString;
}
void interfaceAlphanumerique::drawGraphONV(vector<vector<int>> adjMatrix) const  {
    int numNodes = adjMatrix.size() - 1; // On ignore la première ligne et la première colonne
    string affichage = "\nAffichage alphanumerique : \n";
    string graphString = affichage+"  ";

    // Ajouter les nœuds
    for(int i = 1; i <= numNodes; i++) {
        graphString += to_string(i) + " ";
    }
    graphString += "\n";

    // Ajouter les arêtes
    for(int i = 1; i <= numNodes; i++) {
        graphString += to_string(i) + " ";
        for(int j = 1; j <= numNodes; j++) {
            if(adjMatrix[i][j] == -1){
                graphString += "- ";
            } else {
                graphString += to_string(adjMatrix[i][j]) + " ";
            }
        }
        graphString += "\n";
    }

    cout << graphString;
}



