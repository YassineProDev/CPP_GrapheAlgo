#include "dijkstra.h"

dijkstra::dijkstra(grapheOrienteV graph) : graphe{graph}
{


        vector<Arete> aretes;
        aretes.resize(graphe.nbArc);
        conversion(aretes);
        int n=graphe.nbSommet+1;

        adjList.resize(n);

        // ajoute des ar�tes au graphe orient�
        for (Arete const &a: aretes)
        {
            // ins�re � la fin
            adjList[a.source].push_back(a);
        }

            // ex�cute l'algorithme de Dijkstra � partir de chaque n�ud
    for (int source = 0; source < n; source++) {
        CheminPlusCourt(source, n);
    }
}

void dijkstra::afficheChemin(vector<int> const &prec, int i, int source)
{
    if (i < 0) {
        return;
    }
    afficheChemin(prec, prec[i], source);
    if (i != source) {
        cout << ", ";
    }
    cout << i;
}

// Ex�cute l'algorithme de Dijkstra sur le graphe donn�
void dijkstra::CheminPlusCourt(int source, int n)
{
    // cr�e un min-heap et pousse le n�ud source ayant une distance de 0
    priority_queue<Sommet, vector<Sommet>, comp> file;
    file.push({source, 0});

    // d�finit la distance initiale de la source � `v` comme infini
    vector<int> dist(n, INT_MAX);

    // la distance de la source � elle-m�me est nulle
    dist[source] = 0;

    // array bool�en pour suivre les sommets pour lesquels le minimum
    // le co�t est d�j� trouv�
    vector<bool> done(n, false);
    done[source] = true;

    // stocke le pr�d�cesseur d'un sommet (dans un chemin d'impression)
    vector<int> prec(n, -1);

    // ex�cuter jusqu'� ce que le Min-Heap soit vide
    while (!file.empty())
    {
        // Supprime et renvoie le meilleur sommet
        Sommet sommet = file.top();
        file.pop();

        // r�cup�re le num�ro du sommet
        int u = sommet.numero;

        // faire pour chaque voisin `v` de `u`
        for (auto i: adjList[u])
        {
            int v = i.dest;
            int poid = i.poid;

            // Etape d�tente
            if (!done[v] && (dist[u] + poid) < dist[v])
            {
                dist[v] = dist[u] + poid;
                prec[v] = u;
                file.push({v, dist[v]});
            }
        }

        // marque le sommet `u` comme termin� pour qu'il ne soit plus repris
        done[u] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != source && dist[i] != INT_MAX)
        {
            cout << "Chemin (" << source <<" -> "<< i << "): Cout minimum = "
                 << dist[i] << ", Route = [";
            afficheChemin(prec, i, source);
            cout << "]" << endl;
        }
    }
}

void dijkstra::conversion(vector<Arete>& aretes)
{

cout << endl << endl << endl;

int k=0;
for(int i=1;i<=graphe.nbSommet;i++ )
{
    for(int j=1;j<=graphe.nbSommet;j++)
    {
        if(graphe.matriceCout[i][j] != -1 && (i != j) )
        {
            Arete e{i,j,graphe.matriceCout[i][j]};
            aretes[k] = e;
            k++;
        }

    }
}

for(int i=0;i<aretes.size();i++)
{
    cout << aretes[i].source << " -> " << aretes[i].dest << " poid : " << aretes[i].poid << endl;
}


}
