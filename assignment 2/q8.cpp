#include <iostream>
using namespace std;
int main()
{int n;
cin >>n;
int c=n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
} for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
    if(arr[i]==arr[j]){
       arr[i] = -1;
    }}
}

   for(int i=0;i<n;i++){
   if(arr[i]==-1){
       c--;
   }
} cout<<c;

    return 0;
}