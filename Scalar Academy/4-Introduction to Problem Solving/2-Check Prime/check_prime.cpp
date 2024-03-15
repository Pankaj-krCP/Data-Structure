#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;
    int flag = 0;
    for (int i = 2; i * i <= A; i++)
    {
        if (A % i == 0)
        {
            cout << 0 << endl;
            flag = 1;
            break;
        }
    }
    if (!flag)
        cout << 1 << endl;
    return 0;
}