#include "Container.h"
#include "Plant.h"

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
    Current = Head;
    do 
    {
        ofst << i << ": ";
        Current->plnt->Out_Data(ofst);
        Current = Current->next;
        i++;
    } while (Current != Head);
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