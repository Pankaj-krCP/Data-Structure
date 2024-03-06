#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int freq[1005];
    int dp[1005];
    for (int i = 0; i < 1005; i++)
    {
        freq[i] = dp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    dp[1] = freq[1];

    for (int i = 2; i <= 1000; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * freq[i]);
    }
    cout << dp[1000] << endl;
    return 0;
}