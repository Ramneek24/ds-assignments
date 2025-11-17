#include <iostream>
using namespace std;

void improvedSelection(int a[], int n){
    int left=0, right=n-1;
    while(left<right){
        int minI=left, maxI=right;
        for(int i=left;i<=right;i++){
            if(a[i]<a[minI]) minI=i;
            if(a[i]>a[maxI]) maxI=i;
        }
        swap(a[left],a[minI]);
        if(maxI==left) maxI=minI;
        swap(a[right],a[maxI]);
        left++; right--;
    }
}

int main(){
    int n; cin>>n;
    int a[100];
    for(int i=0;i<n;i++) cin>>a[i];
    improvedSelection(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
