#include <bits/stdc++.h>
using namespace std;

pair<int, int> getAns(int budget, int n, int *fee, int *happiness, pair<int, int> **dp)
{
    pair<int, int> p;
    if (n <= 0)
    {
        p.first = 0;
        p.second = 0;
        return p;
    }

    if (budget <= 0)
    {
        p.first = 0;
        p.second = 0;
        return p;
    }
    if (dp[budget][n].first > -1 && dp[budget][n].second > -1)
    {
        return dp[budget][n];
    }
    pair<int, int> ans;
    //two cases : include last or not include
    if (fee[n - 1] <= budget)
    {
        pair<int, int> option1 = getAns(budget - fee[n - 1], n - 1, fee, happiness, dp);
        option1.first += fee[n - 1];
        option1.second += happiness[n - 1];

        pair<int, int> option2 = getAns(budget, n - 1, fee, happiness, dp);
        if (option1.second > option2.second)
        {
            ans = option1;
        }
        else if (option2.second > option1.second)
        {
            ans = option2;
        }
        else
        {
            if (option1.first < option2.first)
            {
                ans = option1;
            }
            else
            {
                ans = option2;
            }
        }
    }
    else
    {
        ans = getAns(budget, n - 1, fee, happiness, dp);
    }
    dp[budget][n].first = ans.first;
    dp[budget][n].second = ans.second;
    return ans;
}

int main()
{

    while (true)
    {
        int budget, n;
        cin >> budget >> n;
        if (budget == 0 && n == 0)
        {
            break;
        }
        int *fee = new int[n];
        int *happiness = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> fee[i];
            cin >> happiness[i];
        }
        pair<int, int> p;
        pair<int, int> **dp = new pair<int, int> *[budget + 1];
        for (int i = 0; i <= budget; i++)
        {
            dp[i] = new pair<int, int>[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j].first = -1;
                dp[i][j].second = -1;
            }
        }
        p = getAns(budget, n, fee, happiness, dp);
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}