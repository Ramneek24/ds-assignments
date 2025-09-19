#include <iostream>
using namespace std;
#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear, count;

public:
    CircularQueue() { front = 0; rear = -1; count = 0; }

    bool isEmpty() { return (count == 0); }
    bool isFull() { return (count == SIZE); }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % SIZE] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (!isEmpty()) cout << "Front element: " << arr[front] << endl;
        else cout << "Queue is empty!\n";
    }
};

int main() {
    CircularQueue q;
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
