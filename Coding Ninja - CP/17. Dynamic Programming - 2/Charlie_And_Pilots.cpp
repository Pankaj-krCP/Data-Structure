#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
x = difference between number of assistants and captains
*/
ll getprice(int *cap, int *ass, int n, int x, int **dp)
{
    if (n <= 0)
    {
        return 0;
    }
    ll option1, option2, ans;
    if (dp[n][x] > -1)
    {
        return dp[n][x];
    }
    if (x <= 0)
    {
        ans = ass[0] + getprice(cap + 1, ass + 1, n - 1, x + 1, dp);
    }

    else if (x == n)
    {
        ans = cap[0] + getprice(cap + 1, ass + 1, n - 1, x - 1, dp);
    }
    else
    {
        option1 = cap[0] + getprice(cap + 1, ass + 1, n - 1, x - 1, dp);
        option2 = ass[0] + getprice(cap + 1, ass + 1, n - 1, x + 1, dp);
        ans = min(option1, option2);
    }

    dp[n][x] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *cap = new int[n];
    int *ass = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cap[i] >> ass[i];
    }
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    ll ans = getprice(cap, ass, n, 0, dp);
    cout << ans << endl;
    return 0;
}
