#include "distance.h"


distances::distances(grapheOrienteNV graph) : graphe{graph}
{

    int s;
    cout<<"Quel est le sommet dont vous voulez connaitre la distance avec les autres"<<endl;
    cin>>s;

    desc_large1(s);

    for(int i=1; i<dist.size(); i++)
    {
        cout<<"distance entre le sommet "<<s<<" et le sommet "<<i<<" = "<<dist[i]<<endl;;
    }
}


void distances::desc_large1(int r)
{
    int nb_som = graphe.aps[0];

    int i = 0, j = 1, k = 0, ifin, s, t, it;

    vector<int> fil;
    fil.resize(nb_som+1);
    fil[0] = nb_som;

    dist.resize(nb_som+1);

    dist[0] = nb_som;
    fil[1] = r;

    for (int h = 1; h <= nb_som; h++)
        dist[h] = -1;

    dist[r] = 0;

    while ( i < j )
    {
        k++;
        ifin = j;
            while (i < ifin)
            {
                i++;
                s = fil[i];
                it = graphe.aps[s];
                t = graphe.fs[it];
                    while (t > 0)
                    {
                        if (dist[t] == -1)
                        {
                                j++;
                                fil[j] = t;
                                dist[t] = k;
                        }
                        t = graphe.fs[++it];
                    }
            }
    }
}
