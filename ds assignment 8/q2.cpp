#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){ data=x; left=right=NULL; }
};

Node* insertBST(Node* r,int x){
    if(!r) return new Node(x);
    if(x<r->data) r->left=insertBST(r->left,x);
    else r->right=insertBST(r->right,x);
    return r;
}

bool searchR(Node* r,int x){
    if(!r) return false;
    if(r->data==x) return true;
    return x<r->data ? searchR(r->left,x) : searchR(r->right,x);
}

bool searchNR(Node* r,int x){
    while(r){
        if(r->data==x) return true;
        r=x<r->data?r->left:r->right;
    }
    return false;
}

int maxBST(Node* r){
    while(r->right) r=r->right;
    return r->data;
}

int minBST(Node* r){
    while(r->left) r=r->left;
    return r->data;
}

Node* succ(Node* r,int x){
    Node* s=NULL;
    while(r){
        if(x<r->data){ s=r; r=r->left; }
        else r=r->right;
    }
    return s;
}

Node* pred(Node* r,int x){
    Node* p=NULL;
    while(r){
        if(x>r->data){ p=r; r=r->right; }
        else r=r->left;
    }
    return p;
}

int main(){
    Node* r=NULL;
    r=insertBST(r,20);
    insertBST(r,10);
    insertBST(r,30);
    insertBST(r,5);
    insertBST(r,15);

    cout<<searchR(r,15)<<endl;
    cout<<searchNR(r,30)<<endl;
    cout<<minBST(r)<<endl;
    cout<<maxBST(r)<<endl;
    cout<<succ(r,15)->data<<endl;
    cout<<pred(r,15)->data<<endl;
}
