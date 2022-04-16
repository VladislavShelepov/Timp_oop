#pragma once
#include "Plant.h"
#include <fstream>
using namespace std;

class tree : public Plant {
    string name;
    long age;
    enum place { tundra, desert, steppe, forest };
    place origin;
public:
    void In_Data(ifstream& ifst);
    void Out_Data(ofstream& ofst);
    int CountLetters();
    void OutTrees(ofstream& ofst);
    tree() {};
};