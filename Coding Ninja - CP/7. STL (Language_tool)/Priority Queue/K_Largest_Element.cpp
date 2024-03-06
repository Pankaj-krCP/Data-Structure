#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> kLargest(int input[], int n, int k)
{

    priority_queue<int, vector<int>, greater<int>> max;

    for (int i = 0; i < k; i++)
    {
        max.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (max.top() < input[i])
        {
            max.pop();
            max.push(input[i]);
        }
    }
    while (!max.empty())
    {
        cout << max.top() << endl;
        max.pop();
    }
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

    int k;
    cin >> k;

    kLargest(arr, n, k);
    return 0;
}
