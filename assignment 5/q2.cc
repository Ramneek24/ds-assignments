#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = nullptr; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteOccurrences(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* del = head;
            head = head->next;
            delete del;
            count++;
        }
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->next->data == key) {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
                count++;
            } else temp = temp->next;
        }
        cout << "Deleted " << count << " occurrences\n";
    }

    void display() {
        Node* temp = head;
        while (temp) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    list.insert(1); list.insert(2); list.insert(1);
    list.insert(2); list.insert(1); list.insert(3); list.insert(1);

    cout << "Original List: "; list.display();
    list.deleteOccurrences(1);
    cout << "Updated List: "; list.display();
}
