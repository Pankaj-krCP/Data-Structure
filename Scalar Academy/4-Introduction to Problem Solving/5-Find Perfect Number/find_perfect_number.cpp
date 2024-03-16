#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;
    int tmp = 1; // Adding 1 in beginning bcz if i will do it in loop then it will also add number itself
    for (int i = 2; i * i <= A; i++)
    {
        if (A % i == 0)
            tmp += i + A / i;
    }
    if (A == tmp)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }

    return 0;
}