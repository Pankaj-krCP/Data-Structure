#include <bits/stdc++.h>
using namespace std;

int getMaxMoney(int arr[], int n, int i, int temp[])
{
    if (i >= n)
    {
        return 0;
    }
    if (temp[i] > 0)
    {
        return temp[i];
    }
    int maximum = 0;
    int including = arr[i] + getMaxMoney(arr, n, i + 2, temp);
    int not_including = getMaxMoney(arr, n, i + 2, temp);
    maximum = max(including, not_including); 
    temp[i] = maximum;
    return maximum;
}

int main()
{
    int n;
    cin >> n;
    int house[n];
    for (int i = 0; i < n; i++)
    {
        cin >> house[i];
    }
    int temp[10004];
    for (int i = 0; i < 10004; i++)
    {
        temp[i] = 0;
    }
    int i = 1;
    cout << getMaxMoney(house, n, i, temp) << endl;

    return 0;
}