#include "rang.h"



rang::rang(grapheOrienteNV graph) : graphe{graph}
{
    calculRang();
    afficherRang();
}

void rang::afficherRang()
{
    for (int i=1; i<=graphe.aps[0]; i++)
        cout <<"rang["<<i<<"] = "<<tabRang[i]<<endl;
}


void rang::empiler (int x, vector<int> &pilch)
{
    pilch[x] = pilch[0];
    pilch[0] = x;
}

void rang::calculRang()
{
    int n = graphe.aps[0], taillefs = graphe.fs[0], s, k,h,t;

    tabRang.resize(n+1);

    vector<int> ddi;
    vector<int> pilch;
    vector<int> prem;

    ddi.resize(n+1);
    pilch.resize(n+1);
    prem.resize(n+1);

    for(int i=1; i <=n ; i++)
        ddi[i]=0;

    //calcul de ddi
    for(int i=1; i <=taillefs ; i++)
    {
        s=graphe.fs[i];
        if (s >0) ddi[s]++;
    }

    //calcul du rang
    pilch[0]=0;
    for(s = 1; s <= n; s++)
    {
        tabRang[s] = -1; // n : nombre de sommets de G represente l'infini
        if (ddi[s] == 0) empiler(s,pilch);
    }

    k=-1;
    s=pilch[0];
    prem[0] = s;
    while (pilch[0] > 0)
    {
        k++;
        pilch[0] = 0;
        while (s > 0)
        {
            tabRang[s] = k;
            h = graphe.aps[s];
            t = graphe.fs[h];
            while (t > 0)
            {
                ddi[t]--;
                if (ddi[t] == 0) empiler(t,pilch);
                h++;
                t=graphe.fs[h];
            }
            s = pilch[s];
        }
        s = pilch[0];
        prem[k+1] = s;
    }
}















