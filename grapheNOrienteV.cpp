#include "grapheNOrienteV.h"

grapheNOrienteV::grapheNOrienteV()
{
    construireAdjacence();
}


grapheNOrienteV::grapheNOrienteV(string nomFichier)
{
    construireAdjacenceFichier(nomFichier);
}

void grapheNOrienteV::construireAdjacenceFichier(string nomFichier) {
    ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        cout<< "Erreur : impossible d'ouvrir le fichier." << endl;
        return;
    }

    int n, a;

    // Lecture du nombre de sommets et du nombre d'arêtes
    fichier >> n >> a;

    nbSommet = n;
    nbArc = a;

    adjacence.resize(n+1);
    for (auto& ligne : adjacence) {
        ligne.resize(n+1);
    }

    // Initialisation de la matrice d'adjacence à -1
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            adjacence[i][j] = -1;
        }
    }

    matriceCout.resize(n+1);
    for (auto& ligne : matriceCout) {
        ligne.resize(n+1);
    }

    // Initialisation de la matrice de coûts à -1
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            matriceCout[i][j] = -1;
        }
    }

    int s1, s2, p;
    for (int i = 1; i <= a; i++) {
        // Lecture des sommets de l'arête
        fichier >> s1 >> s2;

        // Mise à jour de la matrice d'adjacence
        adjacence[s1][s2] = 1;
        adjacence[s1][0]++;

        adjacence[s2][s1] = 1;
        adjacence[s2][0]++;

        // Lecture du poids de l'arête
        fichier >> p;

        // Mise à jour de la matrice de coûts
        matriceCout[s1][s2] = p;
        matriceCout[s2][s1] = p;
    }

    fichier.close();
}

void grapheNOrienteV::construireAdjacence()
{
    cout << "Donnez le nombre de sommets de votre graphe : "<<endl;
    cin >> nbSommet;
    int n = nbSommet;

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

    matriceCout.resize(n+1);

    for (auto& ligne : matriceCout)
    {
       ligne.resize(n+1);
    }

    for (int i = 0; i <= n; i++)
    {
          for (int j = 0; j <= n; j++)
          {
              if(i==j)
              {
                matriceCout[i][j] = 0;
              }
              else
              {
                matriceCout[i][j] = -1;
              }

          }
    }

    int a;
    cout << "Entrer le nombre d'arretes : ";
    cin >> a;
    nbArc = a;

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

        int p;
        cout<<"Entrez le poid de cette arrete"<<endl;
        cin>>p;
        matriceCout[s1][s2]=p;
        matriceCout[s2][s1]=p;
    }

}

