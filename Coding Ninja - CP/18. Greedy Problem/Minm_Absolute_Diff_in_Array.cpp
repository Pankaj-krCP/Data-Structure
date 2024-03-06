#include <bits/stdc++.h>
using namespace std;

int minAbsoluteDiff(int arr[], int n)
{
    sort(arr, arr + n);
    int minimum = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        minimum = min(minimum, arr[i] - arr[i - 1]);
    }
    return minimum;
}

int main()
{
    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];
    cout << minAbsoluteDiff(input, size) << endl;
    return 0;
}
