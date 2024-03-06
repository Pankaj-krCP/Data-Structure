#include <bits/stdc++.h>
using namespace std;

vector<int> getVoters(int arr[], int n)
{
    vector<int> result;
    sort(arr, arr + n);

    for (int i = 0; i < n;)
    {
        int count = 0;
        int j = i;
        while (j < n && (arr[j] == arr[i]))
        {
            count++;
            j++;
        }
        if (count >= 2)
        {
            result.push_back(arr[i]);
        }
        i = j;
    }

    return result;
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int total = n1 + n2 + n3;
    int arr[total];
    for (int i = 0; i < total; i++)
    {
        cin >> arr[i];
    }

    vector<int> v = getVoters(arr, total);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}