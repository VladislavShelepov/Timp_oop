#pragma once
#include "Plant.h"
#include <fstream>
using namespace std;

class flower : public Plant {

    enum type { domestic, garden, wild };
    type t;

public:
    void In_Data(ifstream& ifst);
    void Out_Data(ofstream& ofst);
    void OutTrees(ofstream& ofst);
    flower() {};
};