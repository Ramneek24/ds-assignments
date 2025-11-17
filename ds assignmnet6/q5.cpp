#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

bool isCircular(Node* head){
    if(!head) return false;
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main(){
    Node* a=new Node(2);
    Node* b=new Node(4);
    Node* c=new Node(6);
    Node* d=new Node(7);
    Node* e=new Node(5);

    a->next=b; b->next=c; c->next=d; d->next=e; e->next=a;

    cout<<(isCircular(a) ? "True" : "False");
}
