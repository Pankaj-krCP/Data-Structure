#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;
    int ans = -1;
    for (int i = 1; i * i <= A; i++)
    {
        if (i * i == A)
            ans = i;
    }
    cout << ans << endl;
    return 0;
}