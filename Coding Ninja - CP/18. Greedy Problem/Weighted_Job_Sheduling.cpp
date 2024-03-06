#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Job
{
    int start;
    int finish;
    int profit;
};

bool compare(Job j1, Job j2)
{
    return j1.finish < j2.finish;
}

//O(log n )

int binarysearch(Job *arr, int index)
{
    int ans = -1;
    int start = 0;
    int end = index - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid].finish <= arr[index].start)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

ll getprofit(Job *arr, int n)
{
    ll *dp = new ll[n]();
    dp[0] = arr[0].profit;
    ll profit;
    for (int i = 1; i < n; i++)
    {
        ll include = arr[i].profit;
        ll exclude = dp[i - 1];
        int betterindex = -1;
        betterindex = binarysearch(arr, i); //return first index from last which for which finish time <= start time of current index
        if (betterindex != -1)
        {
            include += dp[betterindex];
        }
        dp[i] = max(include, exclude);
    }
    return dp[n - 1];
}

//O(n^2)

// ll getprofit(Job *arr, int n)
// {
//     ll *dp = new ll[n]();
//     dp[0] = arr[0].profit;
//     ll profit;
//     for (int i = 1; i < n; i++)
//     {
//         ll include = arr[i].profit;
//         int betterindex = -1;
//         for (int j = i - 1; j >= 0; j--)
//         {
//             if (arr[j].finish <= arr[i].start)
//             {
//                 betterindex = j;
//                 break;
//             }
//         }
//         if (betterindex != -1)
//         {
//             include += dp[betterindex];
//         }
//         dp[i] = max(include, dp[i - 1]);
//     }
//     return dp[n - 1];
// }

int main()
{
    int n;
    cin >> n;
    Job *arr = new Job[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].start;
        cin >> arr[i].finish;
        cin >> arr[i].profit;
    }
    sort(arr, arr + n, compare);
    cout << getprofit(arr, n);
    return 0;
}
