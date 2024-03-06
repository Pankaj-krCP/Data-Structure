#include <bits/stdc++.h>
using namespace std;

vector<int> RemoveDuplicate(vector<int> input)
{
    set<int> s;
    vector<int> result;
    for (int i = 0; i < input.size(); i++)
    {
        if (s.find(input[i]) == s.end())
        {
            s.insert(input[i]);
            result.push_back(input[i]);
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        v.push_back(data);
    }
    vector<int> v1 = RemoveDuplicate(v);
    vector<int>::iterator it;
    for (it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}