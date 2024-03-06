#include <bits/stdc++.h>
using namespace std;

int coin_change(int v, int arr[], int n, int **arr1)
{
    if (v == 0)
    {
        return 1;
    }
    if (v < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 0;
    }
    if (arr1[v][n] > -1)
    {
        return arr1[v][n];
    }
    int first = coin_change(v - arr[0], arr, n, arr1);
    int second = coin_change(v, arr + 1, n - 1, arr1);
    arr1[v][n] = first + second;
    return first + second;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int v;
    cin >> v;
    int **arr1 = new int *[v + 1];
    for (int i = 0; i < v + 1; i++)
    {
        arr1[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            arr1[i][j] = -1;
        }
    }
    cout << coin_change(v, arr, n, arr1) << endl;
    return 0;
}