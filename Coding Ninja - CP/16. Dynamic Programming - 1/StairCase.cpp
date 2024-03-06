#include <bits/stdc++.h>
using namespace std;

long staircase(int n, long *arr = new long[71]())
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (arr[n] > 0)
    {
        return arr[n];
    }
    long steps_3 = staircase(n - 3, arr);
    long steps_2 = staircase(n - 2, arr);
    long step_1 = staircase(n - 1, arr);
    long ans = step_1 + steps_2 + steps_3;
    arr[n - 1] = step_1;
    arr[n - 2] = steps_2;
    arr[n - 3] = steps_3;
    arr[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    long *arr = new long[71];
    for (int i = 0; i < 71; i++)
    {
        arr[i] = 0;
    }
    cout << staircase(n, arr) << endl;
    return 0;
}