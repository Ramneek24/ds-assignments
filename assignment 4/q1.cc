#include <iostream>
using namespace std;
#define SIZE 5

class SimpleQueue {
    int arr[SIZE];
    int front, rear;

public:
    SimpleQueue() { front = -1; rear = -1; }

    bool isEmpty() { return (front == -1 && rear == -1); }
    bool isFull() { return (rear == SIZE - 1); }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void peek() {
        if (!isEmpty()) cout << "Front element: " << arr[front] << endl;
        else cout << "Queue is empty!\n";
    }
};

int main() {
    SimpleQueue q;
    int choice, val;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
        case 2: q.dequeue(); break;
        case 3: q.peek(); break;
        case 4: q.display(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}
