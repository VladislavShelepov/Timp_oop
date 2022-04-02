#include  "Tree.h"

void tree::In_Data(ifstream& ifst) {
    ifst >> name;
    ifst >> age;
}
void tree::Out_Data(ofstream& ofst) {
    ofst << "Name: " << name << endl;
    ofst << "It is a tree. It's age is " << age << " days." << endl;
}
int tree::CountLetters() {
	string letters = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	int cnt = 0;
	for (int i = 0; i < name.length(); i++)
	{
		if (letters.find(name[i]) < letters.length())cnt++;
	}
	return cnt;
}