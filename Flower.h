#pragma once
#include "Plant.h"
#include <fstream>
using namespace std;

class flower : public Plant {
    string name;
    enum type { domestic, garden, wild };
    type t;
    enum place { tundra, desert, steppe, forest };
    place origin;
public:
    void In_Data(ifstream& ifst);
    void Out_Data(ofstream& ofst);
    int CountLetters();
    void OutTrees(ofstream& ofst);
    flower() {};
};