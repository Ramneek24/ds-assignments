#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){ data=x; left=right=NULL; }
};

bool checkBST(Node* r,int minv,int maxv){
    if(!r) return true;
    if(r->data<=minv || r->data>=maxv) return false;
    return checkBST(r->left,minv,r->data) && checkBST(r->right,r->data,maxv);
}

int main(){
    Node* r=new Node(10);
    r->left=new Node(5);
    r->right=new Node(15);

    cout<<(checkBST(r,-1e9,1e9)?1:0);
}
