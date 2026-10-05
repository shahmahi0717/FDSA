#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int capacity;
    int front;
    int rear;
    int count;

public:
    CircularQueue(int n) {
        capacity = n;
        queue = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    // Join operation
    void join(int token) {
        if (count == capacity) {
            cout << "Error: Queue is full. Cannot issue token "
                 << token << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        queue[rear] = token;
        count++;

        printFront();
    }

    // Serve operation
    void serve() {
        if (count == 0) {
            cout << "Error: Queue is empty. Cannot serve." << endl;
            return;
        }

        cout << "Served token: " << queue[front] << endl;

        front = (front + 1) % capacity;
        count--;

        if (count == 0) {
            // Reset rear so the queue is ready for new tokens
            front = 0;
            rear = -1;
        }

        printFront();
    }

    // Print current front token
    void printFront() {
        if (count == 0)
            cout << "Current front: None" << endl;
        else
            cout << "Current front: " << queue[front] << endl;
    }
};

int main() {
    int n, operations;

    cout << "Enter maximum capacity: ";
    cin >> n;

    CircularQueue q(n);

    cout << "Enter number of operations: ";
    cin >> operations;

    cout << "\nEnter operations:\n";
    cout << "J token -> Join\n";
    cout << "S       -> Serve\n\n";

    for (int i = 0; i < operations; i++) {
        char operation;
        cin >> operation;

        if (operation == 'J' || operation == 'j') {
            int token;
            cin >> token;
            q.join(token);
        }
        else if (operation == 'S' || operation == 's') {
            q.serve();
        }
        else {
            cout << "Error: Invalid operation." << endl;
        }
    }

    return 0;
}
