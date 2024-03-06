#include <bits/stdc++.h>
using namespace std;
#define MAXN 16

long long solve(int like[][MAXN], int n)
{
    // Write your code here.
    int *dp = new int[1 << n];
    for (int i = 0; i < (1 << n); i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int mask = 0; mask < ((1 << n) - 1); mask++)
    {
        int temp = mask;
        int count = 0;
        while (temp > 0)
        {
            count += (temp & 1);
            temp = (temp >> 1);
        }

        for (int j = 0; j < n; j++)
        {
            if (!(mask & (1 << j)))
            {
                if (like[count][j] == 1)
                { //count th person has to like
                    dp[mask | (1 << j)] += dp[mask];
                }
            }
        }
    }
    return dp[(1 << n) - 1];
}

int main()
{
    int n, like[MAXN][MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> like[i][j];
        }
    }
    cout << solve(like, n) << endl;
}
