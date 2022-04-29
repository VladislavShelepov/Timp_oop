#include "Plant.h"
#include "Tree.h"
#include "Bush.h"
#include "Flower.h"

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
    else if (k == 3)
    {
        pt = new flower;
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
void Plant::OutTrees(ofstream& ofst)
{
    ofst << endl;
}
int Plant::CountLetters() {
    string letters = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
    int cnt = 0;
    for (int i = 0; i < name.length(); i++)
    {
        if (letters.find(name[i]) < letters.length())cnt++;
    }
    return cnt;
}