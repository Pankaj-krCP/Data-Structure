#include <iostream>
#include <unordered_map>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int *arr, int size)
{
    unordered_map<int, int> freq;
    for (int i = 1; i < size; i++)
    {
        arr[i] += arr[i - 1];
    }
    int m = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            if (m < i + 1)
            {
                m = i + 1;
            }
        }
        else if (freq.count(arr[i]) > 0)
        {
            if (m < i - freq[arr[i]])
            {
                m = i - freq[arr[i]];
            }
        }
        else
        {
            freq[arr[i]] = i;
        }
    }
    return m;
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

    cout << lengthOfLongestSubsetWithZeroSum(arr, n) << endl;
}