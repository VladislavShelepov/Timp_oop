#pragma once
#include <fstream>
#include "Plant.h"
using namespace std;

struct Node {
    Plant* plnt;
    Node* next;
    Node* prev;
    Node(Plant* newplant);
};

class Container {
    Node* Current;
    Node* Head;
    int length;
public:
    void In(ifstream& ifst);
    void Out(ofstream& ofst);
    void OutCountOfLetters(ofstream& ofst);
    void Clear();
    void Sort();
    Container();
    ~Container() { Clear(); }
};
