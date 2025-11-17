#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[m]) m=j;
        swap(a[i],a[m]);
    }
}

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int t=a[i], j=i-1;
        while(j>=0 && a[j]>t){ a[j+1]=a[j]; j--; }
        a[j+1]=t;
    }
}

void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
}

void merge(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) a[k++]=(L[i]<R[j]?L[i++]:R[j++]);
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int partition(int a[], int l, int r){
    int p=a[r], i=l-1;
    for(int j=l;j<r;j++)
        if(a[j]<p){ i++; swap(a[i],a[j]); }
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(int a[], int l, int r){
    if(l<r){
        int pi=partition(a,l,r);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,r);
    }
}

int main(){
    int n; cin>>n;
    int a[100];
    for(int i=0;i<n;i++) cin>>a[i];

    int ch; cin>>ch;

    if(ch==1) selectionSort(a,n);
    else if(ch==2) insertionSort(a,n);
    else if(ch==3) bubbleSort(a,n);
    else if(ch==4) mergeSort(a,0,n-1);
    else if(ch==5) quickSort(a,0,n-1);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
