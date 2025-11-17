#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

void printCLL(Node* head){
    if(!head){ cout<<"Empty"; return; }
    Node* t=head;
    do{
        cout<<t->data<<" ";
        t=t->next;
    }while(t!=head);
    cout<<head->data;
}

int main(){
    Node* a=new Node(20);
    Node* b=new Node(100);
    Node* c=new Node(40);
    Node* d=new Node(80);
    Node* e=new Node(60);

    a->next=b; b->next=c; c->next=d; d->next=e; e->next=a;

    printCLL(a);
}
