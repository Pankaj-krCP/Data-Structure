#include <bits/stdc++.h>
using namespace std;

int getprofit(int *arr, int n, int k, int ongoing, int ***dp)
{
    if (n <= 0)
    {
        return 0;
    }
    if (k <= 0)
    {
        return 0;
    }
    if (dp[n][k][ongoing] > -1)
    {
        return dp[n][k][ongoing];
    }

    int option1, option2, ans;

    option1 = getprofit(arr + 1, n - 1, k, ongoing, dp);

    if (ongoing == 1)
    {
        option2 = getprofit(arr + 1, n - 1, k - 1, 0, dp) + arr[0];
    }
    else
    {
        if (k > 0)
        {
            option2 = getprofit(arr + 1, n - 1, k, 1, dp) - arr[0];
        }
    }

    ans = max(option1, option2);
    dp[n][k][ongoing] = ans;

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;

        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ***dp = new int **[n + 1];

        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int *[n + 1];
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = new int[k + 1];
                for (int l = 0; l <= 1; l++)
                {
                    dp[i][j][l] = -1;
                }
            }
        }

        int ans = getprofit(arr, n, k, 0, dp);
        cout << ans << endl;
    }
    return 0;
}
