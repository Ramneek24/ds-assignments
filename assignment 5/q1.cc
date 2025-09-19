#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = nullptr; }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Key not found!\n"; return; }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) { cout << "List empty!\n"; return; }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) { cout << "List empty!\n"; return; }
        if (!head->next) { delete head; head = nullptr; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) { deleteAtBeginning(); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (!temp->next) { cout << "Key not found!\n"; return; }
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next; pos++;
        }
        cout << "Not found!\n";
    }

    void display() {
        if (!head) { cout << "List empty!\n"; return; }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int ch, val, key;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete Node\n";
        cout << "7. Search\n8. Display\n0. Exit\n";
        cout << "Enter choice: "; cin >> ch;

        switch (ch) {
            case 1: cin >> val; list.insertAtBeginning(val); break;
            case 2: cin >> val; list.insertAtEnd(val); break;
            case 3: cin >> key >> val; list.insertAfter(key, val); break;
            case 4: list.deleteAtBeginning(); break;
            case 5: list.deleteAtEnd(); break;
            case 6: cin >> key; list.deleteNode(key); break;
            case 7: cin >> key; list.searchNode(key); break;
            case 8: list.display(); break;
        }
    } while (ch != 0);
}
