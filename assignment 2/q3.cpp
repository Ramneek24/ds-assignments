#include <iostream>
using namespace std;
int main()
{  int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int d = arr[0]-0;

for(int i=1;i<n;i++){
    if((arr[i]-i)!=d){
        cout<<i+1;
        break;
    } 
}
  

    return 0;
}