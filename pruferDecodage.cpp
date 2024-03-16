#include "pruferDecodage.h"

pruferDecodage::pruferDecodage()
{
    saisieDecodage();
}




void pruferDecodage::saisieDecodage()
{
    int n;

    cout << "Entrer le nombre de sommets : ";
    cin >> n;

    codePrufer.resize(n-1);

    codePrufer[0]=n-2;


    cout <<"Donnez les "<<n-2<<" valeurs du codage de Prufer"<<endl;

    for (int i = 1; i<n-1; i++)
    {
        cin >> codePrufer[i];
    }

    cout << "Les aretes de l'arbre correspondant est :"<<endl;
    decodage();
}

void pruferDecodage::decodage()
{

    adjacence.resize(codePrufer.size()+2);

    for (auto& ligne :  adjacence)
    {
       ligne.resize(codePrufer.size()+2);
    }

    for (int i = 0; i < adjacence.size(); i++)
    {
          for (int j = 0; j < adjacence.size(); j++)
          {
               adjacence[i][j] = 0;
          }
    }



    int m = codePrufer[0], n = m+2;

    std::vector<int> code;
    code.resize(n+1);

    for (int i = 1; i <= n; i++)
        code[i] = 0;

    for (int i = 1; i <= m; i++)
        code[codePrufer[i]]++;

    for (int k = 1; k <= m; k++)
      for (int i = 1; i <= n; i++)
      if (code[i] == 0)
      {
      cout <<"[ "<<codePrufer[k]<<" "<<i<<" ]"<<endl;
      adjacence[codePrufer[k]][i] = 1;
      adjacence[i][codePrufer[k]] = 1;
      code[codePrufer[k]]--;
      code[i] = -1;
      break;
      }



   vector<int> aj;

    cout<<"[ ";
    for (int i = 1; i <= n; i++)
    {
         if (code[i] == 0)
         {
             cout <<i<<" ";
             aj.push_back(i);
         }
    }
    cout << "]"<<endl;

    adjacence[aj[0]][aj[1]] = 1;
    adjacence[aj[1]][aj[0]] = 1;

}



