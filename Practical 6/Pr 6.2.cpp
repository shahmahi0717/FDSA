#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string page;
    Node* next;
};
Node* top = nullptr;
void visit(string page)
{
    Node* newNode = new Node;
    newNode->page = page;
    newNode->next = top;
    top = newNode;
    cout << "Visited: " << page << endl;
    cout << "Current page: " << top->page << endl;
}
void back()
{
    if (top == nullptr)
        {
        cout << "Error: No previous page available." << endl;
        cout << "Current page: None" << endl;
        }
    else
        {
        cout << "Going back from: " << top->page << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
        if (top != nullptr)
            cout << "Current page: " << top->page << endl;
        else
            cout << "Current page: None" << endl;
    }
}
int main()
{
    visit("Google");
    visit("YouTube");
    visit("Wikipedia");
    back();
    back();
    back();
    back();
    visit("GitHub");
    return 0;
}
