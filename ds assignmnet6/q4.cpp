#include <iostream>
using namespace std;

struct Node{
    char data;
    Node *prev,*next;
    Node(char x){ data=x; prev=next=NULL; }
};

bool isPalindrome(Node* head){
    if(!head) return true;
    Node* t=head;
    while(t->next) t=t->next;
    Node* l=head;
    Node* r=t;
    while(l!=r && l->prev!=r){
        if(l->data!=r->data) return false;
        l=l->next;
        r=r->prev;
    }
    return true;
}

int main(){
    Node* a=new Node('r');
    Node* b=new Node('a');
    Node* c=new Node('c');
    Node* d=new Node('e');
    Node* e=new Node('c');
    Node* f=new Node('a');
    Node* g=new Node('r');

    a->next=b; b->prev=a;
    b->next=c; c->prev=b;
    c->next=d; d->prev=c;
    d->next=e; e->prev=d;
    e->next=f; f->prev=e;
    f->next=g; g->prev=f;

    cout<<(isPalindrome(a)?"True":"False");
}
