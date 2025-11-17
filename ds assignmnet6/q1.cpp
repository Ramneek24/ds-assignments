#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

class CircularList {
public:
    Node* head;
    CircularList() { head = NULL; }

    void insertFront(int x) {
        Node* n = new Node(x);
        if (!head) {
            n->next = n;
            head = n;
            return;
        }
        Node* t = head;
        while (t->next != head) t = t->next;
        n->next = head;
        t->next = n;
        head = n;
    }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) {
            n->next = n;
            head = n;
            return;
        }
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    bool insertAfter(int key, int x) {
        if (!head) return false;
        Node* t = head;
        do {
            if (t->data == key) {
                Node* n = new Node(x);
                n->next = t->next;
                t->next = n;
                return true;
            }
            t = t->next;
        } while (t != head);
        return false;
    }

    bool insertBefore(int key, int x) {
        if (!head) return false;
        if (head->data == key) {
            insertFront(x);
            return true;
        }
        Node* p = head;
        Node* c = head->next;
        while (c != head) {
            if (c->data == key) {
                Node* n = new Node(x);
                p->next = n;
                n->next = c;
                return true;
            }
            p = c;
            c = c->next;
        }
        return false;
    }

    bool deleteNode(int key) {
        if (!head) return false;
        if (head->data == key) {
            if (head->next == head) {
                delete head;
                head = NULL;
                return true;
            }
            Node* t = head;
            while (t->next != head) t = t->next;
            Node* d = head;
            head = head->next;
            t->next = head;
            delete d;
            return true;
        }
        Node* p = head;
        Node* c = head->next;
        while (c != head) {
            if (c->data == key) {
                p->next = c->next;
                delete c;
                return true;
            }
            p = c;
            c = c->next;
        }
        return false;
    }

    bool search(int key) {
        if (!head) return false;
        Node* t = head;
        do {
            if (t->data == key) return true;
            t = t->next;
        } while (t != head);
        return false;
    }

    void display() {
        if (!head) {
            cout << "Empty\n";
            return;
        }
        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << endl;
    }
};

int main() {
    CircularList cll;
    int ch, x, key;

    while (true) {
        cout << "\n1.InsertFront 2.InsertEnd 3.InsertAfter 4.InsertBefore 5.Delete 6.Search 7.Display 8.Exit\n";
        cin >> ch;

        if (ch == 8) break;

        if (ch == 1) { cin >> x; cll.insertFront(x); }
        else if (ch == 2) { cin >> x; cll.insertEnd(x); }
        else if (ch == 3) { cin >> key >> x; cll.insertAfter(key, x); }
        else if (ch == 4) { cin >> key >> x; cll.insertBefore(key, x); }
        else if (ch == 5) { cin >> key; cll.deleteNode(key); }
        else if (ch == 6) { cin >> key; cout << (cll.search(key) ? "Found\n" : "Not Found\n"); }
        else if (ch == 7) cll.display();
    }
    return 0;
}
