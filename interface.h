#ifndef INTERFACE_H
#define INTERFACE_H
#include <vector>
#include <memory>
#include <iostream>
class grapheOrienteNV;
class grapheOrienteV;
class grapheNOrienteNV;
class grapheNOrienteV;

class interface
{

    public :
    ~interface() = default;
    virtual void drawGraphNONV(vector<vector<int>> adjMatrix) const = 0;
    virtual void drawGraphNOV(vector<vector<int>> adjMatrix)const = 0;
    virtual void drawGraphONV(vector<vector<int>> adjMatrix)const = 0;
    virtual void drawGraphOV(vector<vector<int>> adjMatrix)const = 0;
};


#endif // INTERFACE_H

