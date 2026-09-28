#include <iostream>
#include <string>
using namespace std;
struct SNode
{
    string name;
    SNode* next;
};
SNode* shead = nullptr;
void displaySingly();
void joinSingly(string name)
{
    SNode* newNode = new SNode;
    newNode->name = name;
    if (shead == nullptr)
        {
        shead = newNode;
        newNode->next = shead;
        }
    else
        {
        SNode* temp = shead;
        while (temp->next != shead)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = shead;
    }
    displaySingly();
}
void leaveSingly(string name)
{
    if (shead == nullptr)
        {
        cout << "Circle is empty." << endl;
        return;
        }
    SNode* current = shead;
    SNode* previous = nullptr;
    do {
        if (current->name == name)
            break;
        previous = current;
        current = current->next;

    } while (current != shead);

    if (current->name != name)
        {
        cout << "Student not found." << endl;
        displaySingly();
        return;
        }
    if (current == shead && current->next == shead)
        {
        delete current;
        shead = nullptr;
        }
    else if (current == shead)
    {
        SNode* last = shead;
        while (last->next != shead)
            {
            last = last->next;
            }
        shead = shead->next;
        last->next = shead;
        delete current;
    }
    else
        {
        previous->next = current->next;
        delete current;
        }
    displaySingly();
}
void displaySingly()
{
    if (shead == nullptr)
        {
        cout << "Circle: Empty" << endl;
        return;
        }
    SNode* current = shead;
    cout << "Circle: ";
    do {
        cout << current->name;
        current = current->next;
        if (current != shead)
            cout << " -> ";
    } while (current != shead);
    cout << " -> " << shead->name << endl;
}
struct DNode
{
    string name;
    DNode* next;
    DNode* prev;
};
DNode* dhead = nullptr;
void displayDoubly();
void joinDoubly(string name)
{
    DNode* newNode = new DNode;
    newNode->name = name;
    if (dhead == nullptr)
        {
        dhead = newNode;
        dhead->next = dhead;
        dhead->prev = dhead;
        }
    else {
        DNode* last = dhead->prev;

        newNode->next = dhead;
        newNode->prev = last;

        last->next = newNode;
        dhead->prev = newNode;
        }
    displayDoubly();
}
void leaveDoubly(string name)
{
    if (dhead == nullptr)
        {
        cout << "Circle is empty." << endl;
        return;
        }
    DNode* current = dhead;
    do {
        if (current->name == name)
            break;

        current = current->next;

    } while (current != dhead);
    if (current->name != name)
        {
        cout << "Student not found." << endl;
        displayDoubly();
        return;
        }
    if (current->next == current)
    {
        delete current;
        dhead = nullptr;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        if (current == dhead)
            dhead = current->next;
        delete current;
    }
    displayDoubly();
}
void displayDoubly()
{
    if (dhead == nullptr)
        {
        cout << "Circle: Empty" << endl;
        return;
        }
    DNode* current = dhead;
    cout << "Circle: ";
    do {
        cout << current->name;
        current = current->next;
        if (current != dhead)
            cout << " <-> ";
    } while (current != dhead);
    cout << " <-> " << dhead->name << endl;
}
int main()
{
    cout << "Singly Circular Linked List" << endl;
    joinSingly("A");
    joinSingly("B");
    joinSingly("C");
    leaveSingly("B");
    joinSingly("D");
    leaveSingly("A");
    cout << endl;
    cout << "Doubly Circular Linked List" << endl;
    joinDoubly("A");
    joinDoubly("B");
    joinDoubly("C");
    leaveDoubly("B");
    joinDoubly("D");
    leaveDoubly("A");
    return 0;
}
