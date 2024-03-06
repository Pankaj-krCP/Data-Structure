#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> kSmallest(int *input, int n, int k)
{

    priority_queue<int> min;

    for (int i = 0; i < k; i++)
    { //PUSH FIRST K ELEMENT IN THE pq
        min.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (min.top() > input[i])
        {

            min.pop();
            min.push(input[i]);
        }
    }

    while (!min.empty())
    {

        cout << min.top() << endl;
        min.pop();
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

    kSmallest(arr, n, k);
    return 0;
}