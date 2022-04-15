#include "Plant.h"
#include "Tree.h"
#include "Bush.h"

Plant* Plant::In(ifstream& ifst) {
    Plant* pt;
    int k;
    ifst >> k;
    if (k == 1)
    {
        pt = new tree;
    }
    else if (k == 2)
    {
        pt = new bush;
    }
    else
    {
        return 0;
    }
    pt->In_Data(ifst);
    return pt;
}
bool Plant::Compare(Plant& p)
{
    return CountLetters() < p.CountLetters();
}