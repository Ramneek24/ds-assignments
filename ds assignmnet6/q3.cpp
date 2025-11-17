#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *prev,*next;
    Node(int x){ data=x; prev=next=NULL; }
};

int sizeDLL(Node* head){
    int c=0;
    while(head){ c++; head=head->next; }
    return c;
}

struct CNode{
    int data;
    CNode* next;
    CNode(int x){ data=x; next=NULL; }
};

int sizeCLL(CNode* head){
    if(!head) return 0;
    int c=0;
    CNode* t=head;
    do{
        c++;
        t=t->next;
    }while(t!=head);
    return c;
}

int main(){
    Node* a=new Node(1);
    a->next=new Node(2);
    a->next->prev=a;

    CNode* x=new CNode(5);
    CNode* y=new CNode(6);
    x->next=y; y->next=x;

    cout<<sizeDLL(a)<<endl;
    cout<<sizeCLL(x)<<endl;
}
