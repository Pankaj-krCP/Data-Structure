#include <iostream>
using namespace std;

int main()
{
    long n;
    cin >> n;

    long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long ans = 0;
    long cur = 0;
    while (cur < (n - 1))
    {
        long next = cur + 1;
        while (next < (n - 1))
        {
            if ((abs(arr[cur]) > (abs(arr[next]))) || ((abs(arr[cur])) == (abs(arr[next])) && arr[cur] > 0))
            {
                break;
            }
            else
            {
                next++;
            }
        }
        ans += ((next - cur) * arr[cur]) + ((next * next - cur * cur) * (arr[cur] * arr[cur]));
        cur = next;
    }
    cout << ans << endl;
    return 0;
}
