#include "danzig.h"
#include <limits.h>

dantzig::dantzig(grapheOrienteV graph) : graphe{graph}
{
    Dantzig();

    cout<<"---------------------------------"<<endl;
    cout<<"  |1 2 3 4 5"<<endl;
    for(int i=1; i<graphe.matriceCout.size(); i++)
    {
        cout<<i<<" |";
        for(int j=1; j<graphe.matriceCout.size(); j++)
        {
            cout<<graphe.matriceCout[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dantzig::Dantzig()
{
    int x;
    for(int k=1;k<graphe.matriceCout.size()-1;k++)
    {
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if((x=graphe.matriceCout[i][j]+graphe.matriceCout[j][k+1])<graphe.matriceCout[i][k+1])
                {
                    graphe.matriceCout[i][k+1]=x;
                }
                if((x=graphe.matriceCout[k+1][j]+graphe.matriceCout[j][i])<graphe.matriceCout[k+1][i])
                {
                    graphe.matriceCout[k+1][i]=x;
                }
            }

            if(graphe.matriceCout[i][k+1]+graphe.matriceCout[k+1][i]<0)
            {
                cout<<"Circuit absorbant passant par "<<i<<" et "<< k+1;
                exit(0);
            }
        }

        for(int i=1; i<=k; i++)
        {
            for(int j=1; j<=k; j++)
            {
                if((x=graphe.matriceCout[i][k+1]+graphe.matriceCout[k+1][i] < graphe.matriceCout[i][j]))
                {
                    graphe.matriceCout[i][j] = x;
                }
            }
        }
    }

}











