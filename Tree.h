#pragma once
#include "Plant.h"
#include <fstream>
using namespace std;

class tree : public Plant {
    string name;
    long age;
public:
    void In_Data(ifstream& ifst);
    void Out_Data(ofstream& ofst);
    int CountLetters();
    tree() {};
};