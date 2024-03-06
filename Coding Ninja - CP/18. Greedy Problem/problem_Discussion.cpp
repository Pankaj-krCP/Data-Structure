#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    int big, small;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    small = arr[0] + k;
    big = arr[n - 1] - k;
    if (small > big)
    {
        int temp = small;
        small = big;
        big = temp;
    }
    for (int i = 1; i < n - 1; i++)
    {
        int sub, add;
        sub = arr[i] - k;
        add = arr[i] + k;
        if (sub >= small || add <= big)
        {
            continue;
        }
        else
        {
            if (big - sub <= add - small)
            {
                small = sub;
            }
            else
            {
                big = add;
            }
        }
    }
    int ans = big - small;
    cout << ans << endl;
}