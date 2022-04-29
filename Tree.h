#pragma once
#include "Plant.h"
#include <fstream>
using namespace std;

class tree : public Plant {
    long age;
public:
    void In_Data(ifstream& ifst);
    void Out_Data(ofstream& ofst);
    void OutTrees(ofstream& ofst);
    tree() {};
};