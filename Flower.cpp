#include "Flower.h"
void flower::In_Data(ifstream& ifst) {
	ifst >> name;
	int a;
	ifst >> a;
	switch (a)
	{
	case 1:
		t = domestic;
		break;
	case 2:
		t = garden;
		break;
	case 3:
		t = wild;
		break;
	}
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

void flower::Out_Data(ofstream& ofst) {
	ofst << "Name: " << name << endl;
	switch (t)
	{
	case 0:
		ofst << "It is a flower. It's domestic." << endl;
		break;
	case 1:
		ofst << "It is a flower. It's garden." << endl;
		break;
	case 2:
		ofst << "It is a flower. It's wild." << endl;
		break;
	}
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
int flower::CountLetters() {
	string letters = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	int cnt = 0;
	for (int i = 0; i < name.length(); i++)
	{
		if (letters.find(name[i]) < letters.length())cnt++;
	}
	return cnt;
};
void flower::OutTrees(ofstream& ofst)
{
	ofst << endl;
}