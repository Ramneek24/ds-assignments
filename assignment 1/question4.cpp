/*
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int k = 0; k < (n / 2); k++)
    {
        int temp = arr[k];
        arr[k] = arr[n - k - 1];
        arr[n - k - 1] = temp;
    }
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
}
*//*
#include <iostream>
using namespace std;
int main()
{
    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    int arr1[n1][m1];
    int arr2[n2][m2];
    int res[n1][m2];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cin >> arr1[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cin >> arr2[i][j];
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < m1; k++)
            {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
*/
