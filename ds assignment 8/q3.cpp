#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){ data=x; left=right=NULL; }
};

Node* insertBST(Node* r,int x){
    if(!r) return new Node(x);
    if(x<r->data) r->left=insertBST(r->left,x);
    else if(x>r->data) r->right=insertBST(r->right,x);
    return r;
}

Node* findMin(Node* r){
    while(r->left) r=r->left;
    return r;
}

Node* deleteBST(Node* r,int x){
    if(!r) return r;
    if(x<r->data) r->left=deleteBST(r->left,x);
    else if(x>r->data) r->right=deleteBST(r->right,x);
    else{
        if(!r->left){ Node* t=r->right; delete r; return t; }
        else if(!r->right){ Node* t=r->left; delete r; return t; }
        Node* t=findMin(r->right);
        r->data=t->data;
        r->right=deleteBST(r->right,t->data);
    }
    return r;
}

int maxDepth(Node* r){
    if(!r) return 0;
    int L=maxDepth(r->left), R=maxDepth(r->right);
    return 1+max(L,R);
}

int minDepth(Node* r){
    if(!r) return 0;
    if(!r->left) return 1+minDepth(r->right);
    if(!r->right) return 1+minDepth(r->left);
    return 1+min(minDepth(r->left),minDepth(r->right));
}

int main(){
    Node* r=NULL;
    r=insertBST(r,50);
    insertBST(r,30);
    insertBST(r,70);
    insertBST(r,20);
    insertBST(r,40);

    r=deleteBST(r,30);

    cout<<maxDepth(r)<<endl;
    cout<<minDepth(r)<<endl;
}
