#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long num;
    cin >> num;
    long long factor = 0;
    for (long long i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            if (num / i != i)
                factor += 2;
            else
                factor += 1;
        }
    }
    cout << factor << endl;

    return 0;
}