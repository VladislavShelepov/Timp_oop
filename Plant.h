#pragma once
#include <fstream>

using namespace std;

class Plant {
public:
    string name;
    enum place { tundra, desert, steppe, forest };
    place origin;
    static Plant* In(ifstream& ifst);
    virtual void In_Data(ifstream& ifst) = 0;
    virtual void Out_Data(ofstream& ofst) = 0;
    int CountLetters();
    bool Compare(Plant& p);
    virtual void OutTrees(ofstream& ofst);
//protected:
//    Plant() {};
};