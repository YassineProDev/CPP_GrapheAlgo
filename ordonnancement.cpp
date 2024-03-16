#include "ordonnancement.h"

ordonnancement::ordonnancement()
{
    saisieTaches();
    Ordonnancement();
    cout<<"Durée de chaque tache :"<<endl;;
    for(int i=1; i<d.size(); i++)
    {
        cout<<nomTaches[i]<<" : "<<d[i]<<endl;
    }

    cout<<"File des predecesseur critique de chaque sommet :";
    for(int i=0; i<fpc.size(); i++)
    {
        cout<<fpc[i]<<" ";
    }
    cout<<endl;

    int sommet = 1;
    cout<<"File des predecesseur critique de chaque sommet :"<<endl;

    cout <<nomTaches[sommet]<< " : ";
    for(int i=1; i<fpc.size(); i++)
    {
        if(fpc[i]==0 && sommet<nomTaches.size()-1)
        {
            sommet++;
            cout<<endl<<nomTaches[sommet]<< " : ";
        }
        else if(sommet<nomTaches.size() && fpc[i]!=0)
        {
            cout<<fpc[i]<<" ";
        }
    }

    cout<<endl<<"Date au plus tot de chaque tache :"<<endl;
    for(int i=1; i<lc.size(); i++)
    {
        cout<<"Tache : "<<nomTaches[i]<<" : "<<lc[i]<<endl;
    }


}

void ordonnancement::saisieTaches()
{
    int m;
    int n;
    cout << "Entrez le nombre de taches: ";
    cin >> n;

    cout << "Donnez le nombre d'arcs de votre graphe     : "<<endl ;
    cin >> m;

    d.resize(n+1);
    fp.resize(n+m+1);
    app.resize(n+1);
    nomTaches.resize(n+1);

    d[0] = n;
    app[0] = n;
    fp[0] = n+m;



    int tache = 0;
    int numeroTache=1;
    int posDansFp = 1;

    while(numeroTache<=n)
    {
        string nom;
        cout << "Donnez le nom de la tache numero "<<numeroTache<<endl;
        cin >> nomTaches[numeroTache];

        int succ = 0;
        app[numeroTache]= posDansFp;
        cout << "Tache " << numeroTache << " Duree : " << endl;
        cin >> d[numeroTache];
        while(succ != -1)
        {
           cout << "Donnez les predecesseur de la tache "<<numeroTache<<" (-1 sinon)" <<endl;
           cin >> succ;
           if(succ!=-1)
           {
               fp[posDansFp] = succ;
               posDansFp++;
           }
        }
        fp[posDansFp] = 0;
        posDansFp++;

        numeroTache++;
    }

}

void ordonnancement::Ordonnancement()
{
   int n = app[0], m = fp[0];

   fpc.resize(m+1);

   appc.resize(n+1);
   appc[0] = n;

   lc.resize(n+1);
   lc[0] = n;

   int kc, t, lg;
   lc[1] = 0;
   fpc[1] = 0;
   appc[1] = 1;
   kc = 1;


    for(int s = 2; s<=n; s++)
    {

        lc[s] = 0;
        appc[s] = kc+1;
            for (int k = app[s]; (t = fp[k]) != 0; k++)
            {
                lg = lc[t] + d[t];
                    if (lg >= lc[s])
                        if (lg > lc[s])
                        {
                            lc[s] = lg;
                            kc = appc[s];
                            fpc[kc] = t;
                        }
                        else
                        {
                            kc++;
                            fpc[kc] = t;
                        }
            }

            kc++ ;
            fpc[kc] = 0;
    }
    fpc[0] = kc;
}
