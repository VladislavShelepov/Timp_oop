#pragma once
#pragma once
#include "Plant.h"
#include <fstream>
using namespace std;

class bush : public Plant {
    string name;
    enum month { January, February, March, April, May, June, July, August, September, October, November, December };
    month blossom;
    enum place { tundra, desert, steppe, forest };
    place origin;
public:
    void In_Data(ifstream& ifst);
    void Out_Data(ofstream& ofst);
    int CountLetters();
    bush() {};
};