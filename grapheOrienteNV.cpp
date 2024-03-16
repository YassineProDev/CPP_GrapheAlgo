#include "grapheOrienteNV.h"

grapheOrienteNV::grapheOrienteNV()
{
   saisie();
   genererMatriceAdjacence();
}


grapheOrienteNV::grapheOrienteNV(string nomFichier)
{
   saisieFichier(nomFichier);
    genererMatriceAdjacence();

}

void grapheOrienteNV::saisieFichier(string nomFichier)
{
    ifstream fichier(nomFichier);
    if (!fichier)
    {
        cout<< "Erreur: Impossible d'ouvrir le fichier " << nomFichier << endl;
        return;
    }

    fichier >> nbSommet >> nbArc;
    int n = nbSommet;
    int m = nbArc;

    aps.resize(n+1);
    fs.resize(n+m+1);
    aps[0] = n;
    fs[0] = n+m;

    int sommet, succ;
    int posDansFs = 1;

    for (int i = 1; i <= n; i++)
    {
        fichier >> sommet;
        aps[i] = posDansFs;
        while (true)
        {
            fichier >> succ;
            if (succ == -1) break;
            fs[posDansFs] = succ;
            posDansFs++;
        }
        fs[posDansFs] = 0;
        posDansFs++;
    }

    matriceAdjacence.resize(n+1);
    for (auto& ligne : matriceAdjacence)
    {
       ligne.resize(n+1);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            matriceAdjacence[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = aps[i]; fs[j] != 0; j++)
        {
            int successeur = fs[j];
            matriceAdjacence[i][successeur] = 1;
        }
    }

    fichier.close();
}

void grapheOrienteNV::saisie()
{


    cout << "Donnez le nombre de sommets de votre graphe : "<<endl;
    cin >> nbSommet;
    int n = nbSommet;
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
           }
        }
        fs[posDansFs] = 0;
        posDansFs++;

        numeroSommet++;
    }

}


void grapheOrienteNV::genererMatriceAdjacence()
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


void grapheOrienteNV::genererFsAps()
{
        int n = matriceAdjacence[0][0];
        int m = matriceAdjacence[0][1];
        aps.resize(n+1);
        aps[0] = n;
        fs.resize(n+m+1);
        fs[0] = n+m;
        int k = 1;
        for (int i = 1; i <= n; i++)
        {
	 	   aps[i] = k;
	 	   for (int j = 1; j <= n; j++)
	 	 	 if (matriceAdjacence[i][j] != 0)
	 	 	 	 fs[k++] = j;
	 	   fs[k++] = 0;
         }
}

void grapheOrienteNV::ajouterSommet()
{
    int nbSom,som;
    cout<<"Entrez le nombre de sommet à ajouter"<<endl;
    cin>>nbSom;

    vector<vector<int>> tmp;
    tmp.resize(nbSom+1);

    for (auto& ligne : tmp)
    {
       ligne.resize(nbSom+1);
    }

    for (int i = 0; i < tmp.size(); i++)
    {
        for (int j = 0; j < tmp.size(); j++)
        {
            if(i<matriceAdjacence.size() && j<matriceAdjacence.size())
            {
                tmp[i][j] = matriceAdjacence[i][j];
            }
            else
            {
                tmp[i][j] = -1;
            }

        }
    }

    matriceAdjacence.resize(nbSom+1);

    for (auto& ligne : matriceAdjacence)
    {
       ligne.resize(nbSom+1);
    }


    for (int i = 0; i < matriceAdjacence.size(); i++)
    {
          for (int j = 0; j < matriceAdjacence.size(); j++)
          {
               matriceAdjacence[i][j] = tmp[i][j];
          }
    }
    int succ;
    for(int i=1; i<=nbSom; i++)
    {
        cout<<"Entrer le sommet"<<endl;
        cin>>som;
        while(som < matriceAdjacence.size())
        {
            cout<<"Entrez un sommet superieur a "<<matriceAdjacence.size()-1<<endl;
            cin>>som;
        }
    }
    genererFsAps();


}
void grapheOrienteNV::ajouterArete()
{
    int s1,s2,nbAr;
    cout<<"Combien d'aretes ?"<<endl;
    cin>>nbAr;
    for(int i=1; i<nbAr; i++)
    {
        cout<<"Entrez le premier sommet de l'arete "<<endl;
        cin>>s1;
        cout<<"Entrez le deuxieme sommet de l'arete"<<endl;
        cin>>s2;
        matriceAdjacence[s1][s2] = 1;
        matriceAdjacence[0][1]++;
    }
    genererFsAps();

}
void grapheOrienteNV::supprimerArete()
{
    int s1,s2,nbAr;
    cout<<"Combien d'aretes ?"<<endl;
    cin>>nbAr;
    for(int i=1; i<nbAr; i++)
    {
        cout<<"Entrez le premier sommet de l'arete "<<endl;
        cin>>s1;
        cout<<"Entrez le deuxieme sommet de l'arete"<<endl;
        cin>>s2;
        matriceAdjacence[s1][s2] = 0;
        matriceAdjacence[0][0]--;
    }
    genererFsAps();
}
