#include  "Tree.h"

void tree::In_Data(ifstream& ifst) {
    ifst >> name;
    ifst >> age;
    int o;
    ifst >> o;
    switch (o)
    {
	case 1:
		origin = tundra;
		break;
	case 2:
		origin = desert;
		break;
	case 3:
		origin = steppe;
		break;
	case 4:
		origin = forest;
		break;
    }
}
void tree::Out_Data(ofstream& ofst) {
    ofst << "Name: " << name << endl;
    ofst << "It is a tree. It's age is " << age << " days." << endl;
	switch (origin)
	{
	case 0:
		ofst << "It grows in tundra." << endl;
		break;
	case 1:
		ofst << "It grows in desert." << endl;
		break;
	case 2:
		ofst << "It grows in steppe." << endl;
		break;
	case 3:
		ofst << "It grows in forest." << endl;
		break;
	}
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