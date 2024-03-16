#include "grapheNOrienteNV.h"

grapheNOrienteNV::grapheNOrienteNV()
{
    construireAdjacence();
}

grapheNOrienteNV::grapheNOrienteNV(string nom_fichier)
{
    construireAdjacenceFichier(nom_fichier);
}


void grapheNOrienteNV::construireAdjacenceFichier(string nom_fichier)
{
    ifstream fichier(nom_fichier);

    if (!fichier)
    {
        cout<< "Impossible d'ouvrir le fichier " << nom_fichier << endl;
        return;
    }

    int n, a;
    fichier >> n >> a;

    adjacence.resize(n+1);

    for (auto& ligne : adjacence)
    {
        ligne.resize(n+1);
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adjacence[i][j] = -1;
        }
    }

    int s1, s2;
    for (int i = 1; i <= a; i++)
    {
        fichier >> s1 >> s2;
        adjacence[s1][s2] = 1;
        adjacence[s1][0]++;

        adjacence[s2][s1] = 1;
        adjacence[s2][0]++;
    }

    fichier.close();
}

void grapheNOrienteNV::construireAdjacence()
{
    int n;

    cout << "Entrer le nombre de sommets : ";
    cin >> n;

    adjacence.resize(n+1);

    for (auto& ligne : adjacence)
    {
       ligne.resize(n+1);
    }

    for (int i = 0; i <= n; i++)
    {
          for (int j = 0; j <= n; j++)
          {
               adjacence[i][j] = 0;
          }
    }

    int a;
    cout << "Entrer le nombre d'arretes : ";
    cin >> a;

    int s1,s2;
    for(int i=1; i<=a; i++)
    {
        cout<<"Entrez le premier sommets de l'arete "<<i<<" : ";
        cin>>s1;
        cout<<"Entrez le deuxieme sommets de l'arete "<<i<<" : ";
        cin>>s2;
        adjacence[s1][s2]=1;
        adjacence[s1][0]++;

        adjacence[s2][s1]=1;
        adjacence[s2][0]++;
    }

}
