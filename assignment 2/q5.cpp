

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int mainDiag[n];
    int upperDiag[n-1];
    int lowerDiag[n-1];

    for (int i = 0; i < n; i++)
    {
        cin >> mainDiag[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> upperDiag[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> lowerDiag[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << mainDiag[i] << " ";
            else if (i == j - 1)
                cout << upperDiag[i] << " ";
            else if (i == j + 1)
                cout << lowerDiag[j] << " ";
            else
                cout <<0<<" ";
        }
        cout << endl;
    }
}



#include<iostream>
using namespace std;
int main(){
        int n;
    cin >> n;

    int total = n * (n + 1) / 2;
    int elements[total];


    for(int i = 0; i < total; i++) elements[i] = 0;


    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> elements[index++];
        }
    }


    index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j) cout << elements[index++] << " ";
            else cout << 0<<" ";
        }
        cout << endl;
}
}



#include<iostream>
using namespace std;
int main(){
        int n;
    cin >> n;

    int total = n * (n + 1) / 2;
    int elements[total];


    for(int i = 0; i < total; i++) elements[i] = 0;


    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j <n; j++) {
            cin >> elements[index++];
        }
    }


    index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i <=j) cout << elements[index++] << " ";
            else cout << 0<<" ";
        }
        cout << endl;
}
}



#include<iostream>
using namespace std;
int main(){
        int n;
    cin >> n;

    int total = n * (n + 1) / 2;
    int elements[total];


    for(int i = 0; i < total; i++) elements[i] = 0;


    cout << "Enter lower triangular elements: "<< endl;
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> elements[index++];
        }
    }


    cout << "Symmetric Matrix:"<< endl;
    index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j) {
                cout << elements[i*(i+1)/2 + j] << " ";
            } else {
                cout << elements[j*(j+1)/2 + i] << " ";
            }
        }
        cout << endl;
    }
}
    


#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    int nm;
    cin >> nm;

    int row[nm], col[nm], val[nm];

    for (int i = 0; i < nm; i++) {
        cin >> row[i];
    }

    for (int j = 0; j < nm; j++) {
        cin >> col[j];
    }

    for (int k = 0; k < nm; k++) {
        cin >> val[k];
    }

    int z = 0;
    int l = 0;
    int h = 0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (z < nm && i == row[z] && j == col[l]) {
                cout << val[h] << " ";
                z++;
                l++;
                h++;
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}




#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < n; i++)
    {
       for (int j = i+1; j< n; j++)
       {
        if (arr[i]>arr[j])
        {
            cnt++;
        }

       }

    }
    cout<<cnt;

}


#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt=0;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        bool flag=false;
       for (int j = 0; j < i; j++)
       {
        if (arr[i]==arr[j])
        {
           flag=true;
        break;
        }

       }
       if(flag!=true){
         cnt++;
       }

    }
    cout<<cnt;

}
    