#include "grapheOrienteV.h"

grapheOrienteV::grapheOrienteV()
{
   saisie();
   genererMatriceAdjacence();
}

grapheOrienteV::grapheOrienteV(string nomFichier)
{
   saisieFichier(nomFichier);
   genererMatriceAdjacence();
}

void grapheOrienteV::saisieFichier(string nomFichier)
{
    ifstream fichier(nomFichier.c_str());
    if (!fichier) {
        cout << "Erreur: impossible d'ouvrir le fichier !" << endl;
        return;
    }

    fichier >> nbSommet;
    int n = nbSommet;

    initialisationMatriceCout(n);

    fichier >> nbArc;
    int m = nbArc;

    aps.resize(n + 1);
    fs.resize(n + m + 1);
    aps[0] = n;
    fs[0] = n + m;

    int sommet = 0;
    int numeroSommet = 1;
    int posDansFs = 1;

    while (numeroSommet <= n) {
        fichier >> sommet;

        int succ = 0;
        aps[numeroSommet] = posDansFs;
        while (succ != -1) {
            fichier >> succ;
            if (succ != -1) {
                fs[posDansFs] = succ;
                posDansFs++;

                int coutArc;
                fichier >> coutArc;
                matriceCout[numeroSommet][succ] = coutArc;
            }
        }
        fs[posDansFs] = 0;
        posDansFs++;

        numeroSommet++;
    }

    fichier.close();

    for(int i=0;i<matriceCout.size();i++)
{
	for(int j=0;j<matriceCout.size();j++)
	{
		cout << matriceCout[i][j] << " ";
	}
	cout<<endl;

}
}


void grapheOrienteV::saisie()
{

    cout << "Donnez le nombre de sommets de votre graphe : "<<endl;
    cin >> nbSommet;
    int n = nbSommet;

    initialisationMatriceCout(n);


    cout << "Donnez le nombre d'arcs de votre graphe     : "<<endl ;
    cin >> nbArc;
    int m=nbArc;

    aps.resize(n+1);
    fs.resize(n+m+1);
    aps[0] = n;
    fs[0] = n+m;

    int sommet = 0;
    int numeroSommet=1;
    int posDansFs = 1;

    while(numeroSommet<=n)
    {
        cout << "Donnez le "<<numeroSommet<<" eme sommet"<<endl;
        cin >> sommet;

        int succ = 0;
        aps[numeroSommet]= posDansFs;
        while(succ != -1)
        {
           cout << "Donnez les successeurs du "<<numeroSommet<<" eme sommet (-1 sinon)" <<endl;
           cin >> succ;
           if(succ!=-1)
           {
               fs[posDansFs] = succ;
               posDansFs++;

               cout<<"Donner la valeur de l'arc entre "<<numeroSommet<<" et "<<succ<<endl;
               cin>>matriceCout[numeroSommet][succ];
           }
        }
        fs[posDansFs] = 0;
        posDansFs++;

        numeroSommet++;
    }

}

void grapheOrienteV::initialisationMatriceCout(int s)
{
    matriceCout.resize(s+1);

    for (auto& ligne : matriceCout)
    {
       ligne.resize(s+1);
    }

    for(int i=1; i<matriceCout.size(); i++)
    {
        for(int j=1; j<matriceCout.size(); j++)
        {
            if(i==j)
            {
                matriceCout[i][j]=0;
            }
            else
            {
                matriceCout[i][j]=-1;
            }
        }
    }
}



void grapheOrienteV::genererMatriceAdjacence()
{
    int k=0;
    int n = aps[0];
    int m = fs[0]-n;

    matriceAdjacence.resize(n+1);

    for (auto& ligne : matriceAdjacence)
    {
       ligne.resize(n+1);
    }



     for (int i = 0; i <= n; i++)
     {
          for (int j = 0; j <= n; j++)
          {
               matriceAdjacence[i][j] = -1;
          }
     }

     matriceAdjacence[0][0] = n;
     matriceAdjacence[0][1] = m;

     for (int i = 1; i <= n; i++)
     {
	 	 	 k = aps[i];
	 	 	 while ( fs[k] != 0 )
	 	 	 {
	 	 	 	 matriceAdjacence[i][fs[k]] = 1;
                 k++;
	 	 	 }
    }

}


