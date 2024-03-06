#include <iostream>
#include <algorithm>
using namespace std;

/*
condition for non-degenerate traingle :
if a,b,c are sides of trianle then a+b > c ,b+c > a,a+c > b
*/

void getans(int *arr, int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        int a = arr[i];
        int b = arr[i + 1];
        int c = arr[i + 2];

        if ((a + b > c) && (b + c > a) && (a + c > b))
        {
            cout << c << " " << b << " " << a << endl;
            return;
        }
    }
    cout << "-1" << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    getans(arr, n);
    return 0;
}
