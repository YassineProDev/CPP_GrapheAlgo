#include "interfaceFichier.h"
#include "grapheNOrienteNV.h"
#include "grapheNOrienteV.h"
#include "grapheOrienteNV.h"
#include "grapheOrienteV.h"

interfaceFichier::interfaceFichier()

{

}

void interfaceFichier::drawGraphNONV(vector<vector<int>> adjMatrix) const {
    int numNoeuds = adjMatrix.size() - 1;
    string affichage = "Affichage Fichier : \n";
    string grapheString = affichage + "  ";

    for (int i = 1; i <= numNoeuds; i++)
    {
        grapheString += to_string(i) + " ";
    }
    grapheString += "\n";

    for (int i = 1; i <= numNoeuds; i++) {
        grapheString += to_string(i) + " ";
        for (int j = 1; j <= numNoeuds; j++)
        {
            grapheString += (adjMatrix[i][j] == 1) ? "-" : " ";
            grapheString += " ";
        }
        grapheString += "\n";
    }
    // on va maintenant ajouter le texte dans le fichier en le creeant
    ofstream fichier("GrapheNonOrienteNonValue.txt");
    if (fichier.is_open())
    {
        fichier << grapheString;
        fichier.close();
        cout << "Le graphe a ete enregistre dans le fichier : " << "GrapheNonOrienteNonValue.txt" << endl;
    }
    else {
        cout << "Erreur : impossible d'ouvrir le fichier de sortie." << endl;
    }
}
void interfaceFichier::drawGraphNOV(vector<vector<int>> adjMatrix) const  {
    int numNoeuds = adjMatrix.size() - 1;
    string affichage = "Affichage Fichier : \n";
    string grapheString = affichage;

    grapheString += "Noeuds : ";
    for(int i = 1; i <= numNoeuds; i++)
    {
        grapheString += to_string(i) + " ";
    }
    grapheString += "\n";

    grapheString += "Aretes : \n";
    for(int i = 1; i <= numNoeuds; i++)
    {
        for(int j = 1; j <= numNoeuds; j++)
        {
            if (adjMatrix[i][j] != -1 && i != j)
            {
                grapheString += "(" + to_string(i) + ", " + to_string(j) + ", " + to_string(adjMatrix[i][j]) + ") ";
            }
        }
        grapheString += "\n";
    }

    ofstream fichier("graphNonOrienteValue.txt");
    if (fichier.is_open())
    {
        fichier << grapheString;
        fichier.close();
        cout << "Le graphe a ete enregistre dans le fichier : " << "graphNonOrienteValue.txt" << endl;
    } else {
        cout << "Erreur : impossible d'ouvrir le fichier" << endl;
    }
}
void interfaceFichier::drawGraphOV(vector<vector<int>> adjMatrix) const {
    int numNoeuds = adjMatrix.size() - 1;
    string affichage = "Affichage Fichier : \n";
    string grapheString = affichage + "  ";

    for (int i = 1; i <= numNoeuds; i++)
    {
        grapheString += to_string(i) + " ";
    }
    grapheString += "\n";

    for (int i = 1; i <= numNoeuds; i++)
    {
        grapheString += to_string(i) + " ";
        for (int j = 1; j <= numNoeuds; j++)
        {
            if (adjMatrix[i][j] > 0)
                {
                grapheString += "1 ";
            }
            else
            {
                grapheString += to_string(adjMatrix[i][j]) + " ";
            }
        }
        grapheString += "\n";
    }

    ofstream fichier("graphOrienteValue.txt");
    if (fichier.is_open())
    {
        fichier << grapheString;
        fichier.close();
        cout << "Le graphe a ete enregistre dans le fichier : " << "graphOrienteValue.txt" << endl;
    }
    else
    {
        cout << "Erreur : impossible d'ouvrir le fichier" << endl;
    }
}
void interfaceFichier::drawGraphONV(vector<vector<int>> adjMatrix) const {
    int numNoeuds = adjMatrix.size() - 1;
    string affichage = "\nAffichage Fichier : \n";
    string grapheString = affichage+"  ";

    for(int i = 1; i <= numNoeuds; i++)
    {
        grapheString += to_string(i) + " ";
    }
    grapheString += "\n";

    for(int i = 1; i <= numNoeuds; i++)
    {
        grapheString += to_string(i) + " ";
        for(int j = 1; j <= numNoeuds; j++)
        {
            if(adjMatrix[i][j] == -1)
            {
                grapheString += "- ";
            }
            else
            {
                grapheString += to_string(adjMatrix[i][j]) + " ";
            }
        }
        grapheString += "\n";
    }

    ofstream fichier("graphOrienteNonValue.txt");
    if (fichier.is_open()) {
        fichier << grapheString;
        fichier.close();
        cout << "Le graphe a ete enregistre dans le fichier : " << "graphOrienteNonValue.txt" << endl;
    } else {
        cout << "Impossible d'ouvrir le fichier " << endl;
    }
}





