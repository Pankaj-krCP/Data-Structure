//Solution 1
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> i1, pair<int, int> i2)
{
    return i1.second < i2.second;
}
int activities(pair<int, int> *arr, int n)
{
    int current_ending_time = arr[0].second;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (current_ending_time <= arr[i].first)
        {
            count += 1;
            current_ending_time = arr[i].second;
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    pair<int, int> *arr = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n, compare);
    cout << activities(arr, n) << endl;
}

//Solution 2:
// #include <bits/stdc++.h>
// using namespace std;

// struct Interval
// {
//     int start;
//     int end;
// };

// bool compare(Interval i1, Interval i2)
// {
//     return i1.end < i2.end; //sort array of structures based on second element in array in increasing order
// }

// int main()
// {
//     int n;
//     cin >> n;
//     Interval *arr = new Interval[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i].start;
//         cin >> arr[i].end;
//     }
//     sort(arr, arr + n, compare);
//     int count = 1;
//     int cur_end = arr[0].end;
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i].start >= cur_end)
//         {
//             count += 1;
//             cur_end = arr[i].end;
//         }
//     }
//     cout << count;
//     return 0;
// }
