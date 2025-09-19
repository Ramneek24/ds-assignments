#include <iostream>
using namespace std;

class Node {
public:
    int data; Node* next;
    Node(int val) { data = val; next = nullptr; }
};

Node* reverse(Node* head) {
    Node* prev = nullptr; Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void display(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: "; display(head);
    head = reverse(head);
    cout << "Reversed List: "; display(head);
}
