#include "kruskal.h"

kruskal::kruskal(grapheNOrienteV graph) : grapheNOV{graph}
{

    graphe g, t;
    conversion(g);
    int n = g.n;
    int *prem = new int[n + 1];
    int *pilch = new int[n + 1];
    int *cfc = new int[n + 1];
    int *NbElem = new int[n + 1];
    for(int i=1; i<=n;i++)
    {
        prem[i] = i;
        pilch[i] = 0;
        cfc[i] = i;
        NbElem[i] = 1;
    }

    trier(g);

    Kruskal(g, t, prem, pilch, cfc,NbElem);

    cout<<"kruskal"<<endl;
    affichet(prem,n);
    affichet(pilch,n);
    affichet(cfc,n);
    affichet(NbElem,n);

    affichage(t);
    delete[] prem;
    delete[] pilch;
    delete[] cfc;
    delete[] NbElem;
}

void kruskal::conversion(graphe &g)
{
    arete ar;

    g.n = grapheNOV.nbSommet;
    g.m = grapheNOV.nbArc;

    int cpt = 0;
    g.a = new arete[g.m];
    for(int k=0; k<=5; k++)
    {
        for(int i=1; i<9; i++)
        {
            for(int j=i; j<9; j++)
            {
                if(grapheNOV.matriceCout[i][j]==k)
                {
                    ar.s = i;
                    ar.t = j;
                    g.a[cpt] = ar;
                    g.a[cpt].p = k;
                    cpt++;
                }
            }
        }
    }
}

void kruskal::affichage(graphe g)
{
    for (int i = 0; i < g.m; i++)
    cout << "Arete No " << i + 1 << " : (" << g.a[i].s << " , " <<
    g.a[i].t << ") --- " << g.a[i].p << endl;
}

void kruskal::trier(graphe &g)
{
    double p;
    for (int i = 0; i < g.m - 1; i++)
    for (int j = i + 1; j < g.m; j++)
    if ((g.a[j].p < g.a[i].p) || (g.a[j].p == g.a[i].p && g.a[j].s
    < g.a[i].t) || (g.a[j].p == g.a[i].p && g.a[j].t < g.a[i].t))
    {
        p = g.a[j].p;
        g.a[j].p = g.a[i].p;
        g.a[i].p = p;
    }
}
void kruskal::affichet(int *a, int n)
{
    for(int i =1; i<=n;i++)
    {
        cout<<a[i]<<"|"<<" ";
    }
    cout<<endl;

}

void kruskal::fusionner(int i, int j, int *prem, int *pilch, int *cfc, int *NbElem)
{
    if (NbElem[i] < NbElem[j])
    {
        int aux = i;
        i = j;
        j = aux;
    }
    int s = prem[j];
    cfc[s] = i;

    while (pilch[s] != 0)
    {
        s = pilch[s];
        cfc[s] = i;
    }
    pilch[s] = prem[i];
    prem[i] = prem[j];
    NbElem[i] += NbElem[j];
}

void kruskal::Kruskal(graphe g, graphe &t, int *prem, int *pilch, int *cfc, int *NbElem)
//Le tableau des arêtes de g est déjà trié
{   int n=g.n;
    t.a = new arete[g.n-1];
    int x; // la 1ère extrémité de l’arête courante
    int y; // la 2ème extrémité de l’arête courante
    int i = 0, j = 0;
    while (j < g.n-1)
    {
        arete ar = g.a[i];
        x = cfc[ar.s];
        y = cfc[ar.t];
        cout<<x<<" "<<y<<endl;
        if (x != y)
        {
            t.a[j++] = g.a[i];
            cout<<x<<" "<<y<<endl;
            affichet(prem,n);
            affichet(pilch,n);
            affichet(cfc,n);
            affichet(NbElem,n);
            fusionner(x, y, prem, pilch, cfc, NbElem);
        }
        i++;
    }
    t.n = g.n;
    t.m = g.n - 1;
}
