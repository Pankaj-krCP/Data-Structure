#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string temp;
multiset<string> st;
void solve(string str, ll pos)
{
    st.insert(temp);

    for (ll i = pos; i < str.length(); i++)
    {
        temp.push_back(str[i]);
        solve(str, i + 1);
        temp.pop_back();
    }
}
int main()
{
    st.clear();
    string str;
    cin >> str;

    temp = "";
    solve(str, 0);

    ll count = 0;
    for (auto it = st.begin(); it != st.end(); it++)
        if (*it == "MOM" || *it == "DAD")
            count++;
    cout << count << endl;
    return 0;
}