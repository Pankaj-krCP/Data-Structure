#include <bits/stdc++.h>
using namespace std;

//RECURSIVE SOLUTION (space : O(n*W))
typedef long long ll;
int helper(int *w, int *v, int n, int W, int **dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return 0;
    }
    if (W == 0)
    {
        return 0;
    }
    if (W < 0)
    {
        return 0;
    }
    if (dp[n][W] > -1)
    {
        return dp[n][W];
    }
    int ans = 0;
    if (W - w[n - 1] >= 0)
    {
        ll option1 = v[n - 1] + helper(w, v, n - 1, W - w[n - 1], dp); //w[n-1] SINCE LAST ELEMENT INDEX IS n-1
        ll option2 = helper(w, v, n - 1, W, dp);
        ans = max(option1, option2);
    }
    else
    {
        ans = helper(w, v, n - 1, W, dp);
    }
    dp[n][W] = ans;
    return ans;
}

int knapsack(int *values, int *weights, int maxWeight, int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[maxWeight + 1];
        for (int j = 0; j <= maxWeight; j++)
        {
            dp[i][j] = -1;
        }
    }
    return helper(weights, values, n, maxWeight, dp);
}



//Iterative Solution
int knapsnack(int *val, int *wt, int W, int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[W + 1];
    }

    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {

            dp[i][w] = dp[i - 1][w];
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
        }
    }

    int ans = dp[n][W];
    for(int i=0;i<=n;i++){
        delete dp[i];
    }
    delete [] dp;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int val[n];
    int wt[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int W;
    cin >> W;
    cout << knapsack(val, wt, W, n) << endl;
    cout << knapsnack(val, wt, W, n) << endl;
}