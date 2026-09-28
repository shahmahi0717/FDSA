#include <iostream>
#include <string>
using namespace std;
struct Node {
    string song;
    Node* prev;
    Node* next;
};
Node* head = nullptr;
void display();
void addBeginning(string song)
{
    Node* newNode = new Node;
    newNode->song = song;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr)
        {
        head = newNode;
        }
    else
        {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        }
    display();
}
void addEnd(string song)
{
    Node* newNode = new Node;
    newNode->song = song;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr)
        {
        head = newNode;
        }
    else
        {
        Node* current = head;

        while (current->next != nullptr)
            {
            current = current->next;
            }

        current->next = newNode;
        newNode->prev = current;
        }
    display();
}
void insertAfter(string target, string song)
{
    Node* current = head;
    while (current != nullptr && current->song != target)
        {
        current = current->next;
        }
    if (current == nullptr)
    {
        cout << "Song not found." << endl;
        display();
        return;
    }
    Node* newNode = new Node;
    newNode->song = song;
    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != nullptr)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
    display();
}
void removeFirst() {
    if (head == nullptr)
        {
        cout << "Playlist is empty." << endl;
        display();
        return;
        }
    Node* temp = head;
    head = head->next;
    if (head != nullptr)
        {
        head->prev = nullptr;
        }
    delete temp;
    display();
}
int countSongs()
{
    int count = 0;
    Node* current = head;
    while (current != nullptr)
        {
        count++;
        current = current->next;
        }
    return count;
}
void display()
{
    Node* current = head;
    cout << "Playlist: ";

    if (current == nullptr)
        {
        cout << "Empty";
        }
    while (current != nullptr)
    {
        cout << current->song;
        if (current->next != nullptr)
        {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
    cout << "Number of songs: " << countSongs() << endl;
    cout << "------------------------" << endl;
}
int main() {
    addBeginning("Song A");
    addEnd("Song C");
    insertAfter("Song A", "Song B");
    addBeginning("Song X");
    removeFirst();
    insertAfter("Song Z", "Song D");
    return 0;
}
