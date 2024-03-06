#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007;

long long countBST(int n, int arr[])
{
    if (n == 0 || n == 1)
        return 1;
    if (arr[n] > 0)
        return arr[n];
    long long count = 0;
    for (int i = 1; i <= n; i++)
    {
        long long left = countBST(i - 1, arr) % MOD;
        arr[i - 1] = left;
        long long right = countBST(n - i, arr) % MOD;
        arr[n - i] = right;
        count += (left * right) % MOD;
    }
    arr[n] = count;
    return count;
}

int main()
{
    int n;
    cin >> n;
    int arr[1001];
    for (int i = 0; i < 1001; i++)
    {
        arr[i] = 0;
    }
    cout << countBST(n, arr) << endl;
    return 0;
}