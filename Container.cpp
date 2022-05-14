#include "Container.h"
#include "Plant.h"
#include <iostream>
#include <string>

Node::Node(Plant* newplnt)
{
	plnt = newplnt;
	next = NULL;
	prev = NULL;
}
Container::Container()
{
	Current = NULL;
    Head = NULL;
	length = 0;
}
void Container::In(ifstream& ifst) {
    while (!ifst.eof())
    {
        Node* newNode;
        newNode = new Node((Plant::In(ifst)));
        if (Head == NULL)
        {
            Head = newNode;
            Head->next = newNode;
            Head->prev = newNode;
            length = 1;
        }
        else
        {
            Current = Head;
            while (Current->next != Head)
            {
                Current = Current->next;
            }
            Current->next = newNode;
            Current->next->prev = Current;
            Current = Current->next;
            Current->next = Head;
            Head->prev = Current;



            length++;
        }
    }
}

void Container::Clear() {
    Current = NULL;
    Head = NULL;
    length = 0;
};

void Container::Out(ofstream& ofst) {
    ofst << "Container contains " << length << " elements." << endl;

    int i = 1;
    if (Head == NULL) 
    {
        return;
    }
    //Sort();
    Current = Head;
    do 
    {
        ofst << i << ": ";
        Current->plnt->Out_Data(ofst);
        OutCountOfLetters(ofst);
        Current = Current->next;
        i++;
    } while (Current != Head);
}

void Container::OutCountOfLetters(ofstream& ofst)
{
    ofst << "count of consonants: " << Current->plnt->CountLetters() << endl;
}

void Container::Sort()
{
    Node* curr1 = Head;
    Node* curr2 = Head;
    do {
        curr2 = curr1->next;
        while (curr2 != Head) {
            if (curr1->plnt->Compare(*curr2->plnt))
            {
                swap(curr1->plnt, curr2->plnt);
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    } while (curr1 != Head);
}
void Container::OutTrees(ofstream& ofst) {
    int i = 1;
    if (Head == NULL)
    {
        return;
    }
    Current = Head;
    do
    {
        ofst << i << ": ";
        if (Current->plnt)Current->plnt->OutTrees(ofst);
        Current = Current->next;
        i++;
    } while (Current != Head);
}
bool fileCheck(ifstream& ifst, ofstream& ofst)
{
	bool result = true;
	string digits = "0123456789";
	char tmp[100];
	string tmps;


	if (!ifst.is_open())
	{
		cout << "Input file was not found.";
		exit(1);
	}
	if (!ofst.is_open())
	{
		cout << "Output file was not found.";
		exit(1);
	}
	int cnt = 1;
	//type check
	while (!ifst.eof())
	{
		ifst.getline(tmp, 100, '\n');
		tmps = (tmp);
		if (tmps == "")
		{
			cout << cnt << " Error: Type is a blank string.\n";
			result = false;
			exit(1);
		}
		for (int i = 0; i < tmps.length(); i++)
		{
			if (!(digits.find(tmps[i]) < digits.length()))
			{
				cout << cnt << " Error: Type definition contains incorrect characters.\n";
				result = false;
				exit(1);
			}
		}
		int type = std::stoi(tmps);
		if (type <= 0 || type > 3)
		{
			cout << cnt << " Error: Type is out of range.\n";
			result = false;
			exit(1);
		}
		//
		//name
		ifst.getline(tmp, 100, '\n');
		tmps = (tmp);
		if (tmps == "")
		{
			cout << cnt << " Error: Name of the plant is a blank string.\n";
			result = false;
			exit(1);
		}
		//
		//for different types
		switch (type)
		{
		case 1:
		{
			//tree - age
			ifst.getline(tmp, 100, '\n');
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The tree's age is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (!(digits.find(tmps[i]) < digits.length()))
				{
					cout << cnt << " Error: The tree's age contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			int age = std::stoi(tmps);
			if (age <= 0)
			{
				cout << cnt << " Error: The tree's age is out of range.\n";
				result = false;
				exit(1);
			}
			break;
		}
		case 2:
		{
			//bush - blossom
			ifst.getline(tmp, 100, '\n');
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The flowering month is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (!(digits.find(tmps[i]) < digits.length()))
				{
					cout << cnt << " Error: The flowering month contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			int type = std::stoi(tmps);
			if (type <= 0 || type > 12)
			{
				cout << cnt << " Error: The flowering month is out of range.\n";
				result = false;
				exit(1);
			}
			break;
		}
		case 3:
		{
			// flower - type
			ifst.getline(tmp, 100, '\n');
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The flower's type is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (!(digits.find(tmps[i]) < digits.length()))
				{
					cout << cnt << " Error: The flower's type contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			int type = std::stoi(tmps);
			if (type <= 0 || type > 3)
			{
				cout << cnt << " Error: The flower's type is out of range.\n";
				result = false;
				exit(1);
			}
			break;
		}
		}
		//
		//origin
		ifst.getline(tmp, 100, '\n');
		tmps = (tmp);
		if (tmps == "")
		{
			cout << cnt << " Error: The origin is a blank string.\n";
			result = false;
			exit(1);
		}
		for (int i = 0; i < tmps.length(); i++)
		{
			if (!(digits.find(tmps[i]) < digits.length()))
			{
				cout << cnt << " Error: The origin contains incorrect characters.\n";
				result = false;
				exit(1);
			}
		}
		int origin = std::stoi(tmps);
		if (origin <= 0 || origin > 4)
		{
			cout << cnt << " Error: The origin is out of range.\n";
			result = false;
			exit(1);
		}
		//
		cnt++;
	}
	return result;
}