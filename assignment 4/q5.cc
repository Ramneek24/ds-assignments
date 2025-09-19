#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q1.push(x);
    }
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
        swap(q1, q2);
    }
    void top() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        cout << "Top: " << q1.front() << endl;
        q2.push(q1.front());
        q1.pop();
        swap(q1, q2);
    }
    bool empty() {
        return q1.empty();
    }
};

class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }
    void top() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top: " << q.front() << endl;
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    StackTwoQueues s2;
    StackOneQueue s1;
    int choice, method, val;

    while (true) {
        cout << "\n--- Stack Using Queues ---\n";
        cout << "1. Use Two Queues\n";
        cout << "2. Use One Queue\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> method;

        if (method == 3) break;

        cout << "1. Push\n2. Pop\n3. Top\n4. Exit\n";
        while (true) {
            cout << "Enter operation: ";
            cin >> choice;
            if (choice == 4) break;

            if (method == 1) { // Two queues
                switch (choice) {
                    case 1: cout << "Enter value: "; cin >> val; s2.push(val); break;
                    case 2: s2.pop(); break;
                    case 3: s2.top(); break;
                    default: cout << "Invalid choice\n";
                }
            } else { // One queue
                switch (choice) {
                    case 1: cout << "Enter value: "; cin >> val; s1.push(val); break;
                    case 2: s1.pop(); break;
                    case 3: s1.top(); break;
                    default: cout << "Invalid choice\n";
                }
            }
        }
    }
    return 0;
}

