#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll m, n;
    cin >> n >> m;

    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    queue<ll> q;
    ll count_m = 0;
    ll end_p = n - 1;
    ll ans;

    while (m--)
    {
        ll curr_m;
        cin >> curr_m;
        for (; count_m < curr_m; count_m++)
        {
            if (end_p >= 0 && (q.empty() || (arr[end_p] >= q.front())))
            {
                ans = arr[end_p];
                end_p--;
            }
            else
            {
                ans = q.front();
                q.pop();
            }
            q.push(ans / 2);
        }
        cout << ans << endl;
    }

    return 0;
}