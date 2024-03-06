#include <iostream>
#include <map>
using namespace std;

void intersection(int *input1, int *input2, int size1, int size2)
{
    map<int, int> mapp;
    for (int i = 0; i < size1; i++)
        mapp[input1[i]]++;
    for (int i = 0; i < size2; i++)
    {
        if (mapp[input2[i]] > 0)
        {
            mapp[input2[i]]--;
            cout << input2[i] <<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        int input1[n];
        for (int i = 0; i < n; i++)
        {
            cin >> input1[i];
        }

        int m;
        cin >> m;
        int input2[m];
        for (int i = 0; i < m; i++)
        {
            cin >> input2[i];
        }

        intersection(input1, input2, n, m);
    }

    return 0;
}