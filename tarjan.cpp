#include "tarjan.h"

tarjan::tarjan(grapheOrienteNV graph) : graphe{graph}
{
    this->V = graphe.nbSommet + 1;
    adj = new list<int>[V];



    int k = 0;
    for (int i = 1; i <= graphe.nbSommet; i++)
    {
        for (int j = 1; j <= graphe.nbSommet; j++)
        {
            if (graphe.matriceAdjacence[i][j] == 1) // à changer le <9
            {
                ajouteArete(i, j);
            }
        }
    }
    cout << "Liste des CFC (ligne par ligne) :" << endl;
    CFC();

}

void tarjan::ajouteArete(int v, int w)
{
    adj[v].push_back(w);
}

void tarjan::SCCUtil(int u, int disc[], int low[], stack<int>* st, bool stackMember[])
{

    static int time = 0;

    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;

        if (disc[v] == -1)
        {
            SCCUtil(v, disc, low, st, stackMember);

            low[u] = min(low[u], low[v]);
        }

        else if (stackMember[v] == true)
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    int w = 0;
    if (low[u] == disc[u])
    {
        while (st->top() != u)
        {
            w = (int)st->top();
            cout << w << " ";
            stackMember[w] = false;
            st->pop();
        }
        w = (int)st->top();
        cout << w << "\n";
        stackMember[w] = false;
        st->pop();
    }
}

void tarjan::CFC()
{
    int* disc = new int[V];
    int* low = new int[V];
    bool* stackMember = new bool[V];
    stack<int>* st = new stack<int>();

        for (int i = 1; i < V; i++) {
            disc[i] = NIL;
            low[i] = NIL;
            stackMember[i] = false;
        }
        // Appel récursivement la méthode pour trouver les CFC
        for (int i = 1; i < V; i++)
            if (disc[i] == NIL)
                SCCUtil(i, disc, low, st, stackMember);
}
