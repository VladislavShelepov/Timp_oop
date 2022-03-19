#pragma once
#include <fstream>

using namespace std;

class Plant {
public:
    static Plant* In(ifstream& ifst);
    virtual void In_Data(ifstream& ifst) = 0;
    virtual void Out_Data(ofstream& ofst) = 0;
//protected:
//    Plant() {};
};