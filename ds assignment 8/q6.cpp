#include <iostream>
using namespace std;

int h[100], sz=0;

void push(int x){
    h[sz]=x;
    int i=sz++;
    while(i>0 && h[(i-1)/2]<h[i]){
        swap(h[i],h[(i-1)/2]);
        i=(i-1)/2;
    }
}

int pop(){
    int x=h[0];
    h[0]=h[--sz];
    int i=0;
    while(true){
        int l=2*i+1, r=2*i+2, mx=i;
        if(l<sz && h[l]>h[mx]) mx=l;
        if(r<sz && h[r]>h[mx]) mx=r;
        if(mx==i) break;
        swap(h[i],h[mx]);
        i=mx;
    }
    return x;
}

int main(){
    push(10);
    push(40);
    push(20);
    cout<<pop()<<" "<<pop()<<" "<<pop();
}
