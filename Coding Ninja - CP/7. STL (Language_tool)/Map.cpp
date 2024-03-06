#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 5};

    //in increasing order
    // map<int, int> m;
    // for (int i = 0; i < 7; i++)
    // {
    //     m[arr[i]] = m[arr[i]] + 1;
    // }

    //in decreasing order
    map<int, int,greater<int>> m;
    for (int i = 0; i < 7; i++)
    {
        m[arr[i]] = m[arr[i]] + 1;
    }
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
    cout << endl;
    m.erase(1);
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
    return 0;
}