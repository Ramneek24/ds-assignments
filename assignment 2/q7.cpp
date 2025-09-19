#include <iostream>
using namespace std;
int main()
{int n;
cin >>n;
int c=0;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(arr[i]>arr[j]){
            c++;}
        
    }
} cout<<c;
return 0 ;
}