#include <iostream>
using namespace std;
const int MAX = 5;
int stackArr[MAX];
int top = -1;
void displayTop()
{
    if (top == -1)
        {
        cout << "Top tray: Empty" << endl;
        }
    else
        {
        cout << "Top tray: " << stackArr[top] << endl;
        }
}
void placeTray(int tray)
{
    if (top == MAX - 1)
        {
        cout << "Error: Stack is full. Cannot place tray " << tray << endl;
        }
    else
        {
        top++;
        stackArr[top] = tray;
        cout << "Placed tray: " << tray << endl;
        }
    displayTop();
}
void takeTray()
{
    if (top == -1)
        {
        cout << "Error: Stack is empty. Cannot take a tray." << endl;
        }
    else
        {
        cout << "Taken tray: " << stackArr[top] << endl;
        top--;
    }
    displayTop();
}
int main()
{
    placeTray(10);
    placeTray(20);
    placeTray(30);
    takeTray();
    placeTray(40);
    placeTray(50);
    placeTray(60);
    placeTray(70);
    takeTray();
    takeTray();
    return 0;
}
