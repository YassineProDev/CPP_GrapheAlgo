#include "pruferCodage.h"

pruferCodage::pruferCodage(grapheNOrienteNV graph) : graphe{graph}
{
    coderPrufer();
}


void pruferCodage::coderPrufer()
{
	int nb_som = graphe.adjacence.size()-1;

	vector<int> prufer;
    prufer.resize(nb_som-1);

    vector<vector<int>> matriceAdjacence;

    matriceAdjacence.resize(graphe.adjacence.size());

    for (auto& ligne :  matriceAdjacence)
    {
       ligne.resize(graphe.adjacence.size());
    }
    for (int i = 0; i < graphe.adjacence.size(); i++)
    {
          for (int j = 0; j < graphe.adjacence.size(); j++)
          {
               matriceAdjacence[i][j] = 0;
          }
    }


    for(int i=0; i<graphe.adjacence.size();i++)
    {
        for(int j=0; j<graphe.adjacence.size();j++)
        {
             matriceAdjacence[i][j] = graphe.adjacence[i][j];
        }
    }


	prufer[0] = nb_som-2;
	int k = 1;
	while (k <= nb_som-2)
	{
	    int i = 1;
		while(i<=nb_som && matriceAdjacence[i][0]!=1)
        {
            i++;
        }


		int j=1;
		while(j<=nb_som && matriceAdjacence[i][j]!=1)
        {
            j++;
        }
		prufer[k++]=j;
		matriceAdjacence[i][j]=0;
		matriceAdjacence[j][i]=0;
		matriceAdjacence[i][0]=0;
		matriceAdjacence[j][0]--;
	}


	cout << "Le codage de Prufer est : ";
    for (int i = 1; i < prufer.size(); i++) {
        cout << prufer[i] << " ";
    }
    cout << endl;
}




