#include  "Tree.h"

void tree::In_Data(ifstream& ifst) {
    ifst >> name;
    ifst >> age;
}
void tree::Out_Data(ofstream& ofst) {
    ofst << "Name: " << name << endl;
    ofst << "It is a tree. It's age is " << age << " days." << endl;
}
void tree::OutTrees(ofstream& ofst)
{
    Out_Data(ofst);
}