#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x) {
    return new Node{x, NULL, NULL};
}

bool check(Node* root, unordered_set<int>& s) {
    if (!root) return false;

    if (s.count(root->data)) return true;

    s.insert(root->data);

    return check(root->left, s) || check(root->right, s);
}

bool hasDuplicate(Node* root) {
    unordered_set<int> s;
    return check(root, s);
}

int main() {
    Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->right->left = newNode(3); 

    cout << (hasDuplicate(root) ? "Duplicates Found" : "No Duplicates");
}
