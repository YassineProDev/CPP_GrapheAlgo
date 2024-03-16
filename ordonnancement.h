#include <iostream>
#include <vector>
#include <string>

using namespace std;


class ordonnancement
{
public :
    ordonnancement();
    void saisieTaches();
    void Ordonnancement();
private :
    vector<int> d;
    vector<int> fp;
    vector<int> app;

    vector<int> fpc;
    vector<int> appc;
    vector<int> lc;

    vector<string> nomTaches;
};
