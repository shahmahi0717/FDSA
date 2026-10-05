#include <iostream>
using namespace std;

struct Node {
    int patient;
    Node* next;
};

class PatientQueue {
private:
    Node* front;
    Node* rear;

public:
    PatientQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Arrive operation
    void arrive(int patient) {
        Node* newNode = new Node;
        newNode->patient = patient;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        printFront();
    }

    // Attend operation
    void attend() {
        if (front == nullptr) {
            cout << "Error: No patients waiting." << endl;
            return;
        }

        cout << "Attended patient: " << front->patient << endl;

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }

        printFront();
    }

    // Display current front patient
    void printFront() {
        if (front == nullptr) {
            cout << "Current front: None" << endl;
        }
        else {
            cout << "Current front: " << front->patient << endl;
        }
    }
};

int main() {
    int operations;

    PatientQueue q;

    cout << "Enter number of operations: ";
    cin >> operations;

    cout << "\nEnter operations:\n";
    cout << "A patient -> Arrive\n";
    cout << "T         -> Attend\n\n";

    for (int i = 0; i < operations; i++) {
        char operation;
        cin >> operation;

        if (operation == 'A' || operation == 'a') {
            int patient;
            cin >> patient;
            q.arrive(patient);
        }
        else if (operation == 'T' || operation == 't') {
            q.attend();
        }
        else {
            cout << "Error: Invalid operation." << endl;
        }
    }

    return 0;
}
