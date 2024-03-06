#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int *input, int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[input[i]]++;
    }
    int maxim = m[input[0]];
    int ans = input[0];
    int j = 1;
    while (j < n)
    {
        if (m[input[j]] > maxim)
        {
            maxim = m[input[j]];
            ans = input[j];
        }
        j++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = highestFrequency(arr, n);
    cout << ans << endl;
    return 0;
}