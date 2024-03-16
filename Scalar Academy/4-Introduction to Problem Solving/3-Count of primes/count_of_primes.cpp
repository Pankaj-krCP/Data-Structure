#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count_primes = 0;
    if (n >= 2)
        count_primes = 1;
    for (int i = 3; i <= n; i++)
    {
        int flag = 0;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            count_primes++;
    }
    cout << count_primes << endl;
    return 0;
}