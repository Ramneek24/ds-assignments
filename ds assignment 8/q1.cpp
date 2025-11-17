#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){ data=x; left=right=NULL; }
};

void preorder(Node* r){
    if(!r) return;
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node* r){
    if(!r) return;
    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

void postorder(Node* r){
    if(!r) return;
    postorder(r->left);
    postorder(r->right);
    cout<<r->data<<" ";
}

int main(){
    Node* r=new Node(1);
    r->left=new Node(2);
    r->right=new Node(3);
    r->left->left=new Node(4);
    r->left->right=new Node(5);

    preorder(r);
    cout<<endl;
    inorder(r);
    cout<<endl;
    postorder(r);
}
