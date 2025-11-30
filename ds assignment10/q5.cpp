#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasLoop(Node* head) {
    unordered_set<Node*> s;

    while (head) {
        if (s.count(head)) return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}

int main() {
    Node* n1 = new Node{1,NULL};
    Node* n2 = new Node{2,NULL};
    Node* n3 = new Node{3,NULL};
    Node* n4 = new Node{4,NULL};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;  // loop

    cout << (hasLoop(n1) ? "true" : "false");
}
