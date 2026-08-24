#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node* next;
};

// Insert a token at the end
void insert(Node*& front, Node*& rear, int token)
{
    Node* newNode = new Node;
    newNode->token = token;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Display from front to rear
void display(Node* front)
{
    Node* temp = front;

    while (temp != NULL)
    {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Delete a node by value
void deleteValue(Node*& front, Node*& rear, int value)
{
    if (front == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    // Delete first node
    if (front->token == value)
    {
        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
        return;
    }

    Node* temp = front;

    while (temp->next != NULL && temp->next->token != value)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Token not found." << endl;
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;

    if (deleteNode == rear)
        rear = temp;

    delete deleteNode;
}

// Reverse printing
void reversePrint(Node* front)
{
    if (front == NULL)
        return;

    reversePrint(front->next);
    cout << front->token << " ";
}

int main()
{
    Node* front = NULL;
    Node* rear = NULL;

    // Creating linked list
    insert(front, rear, 101);
    insert(front, rear, 102);
    insert(front, rear, 103);
    insert(front, rear, 104);
    insert(front, rear, 105);

    cout << "Original List: ";
    display(front);

    // Delete token 103
    deleteValue(front, rear, 103);

    cout << "After Deletion: ";
    display(front);

    // Reverse printing
    cout << "Reverse List: ";
    reversePrint(front);

    return 0;
}
