#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> pisano(int m)
{
    vector<int> v;
    int current = 0, next = 1;

    v.push_back(current);

    if (m < 2)
        return v;
    current = (next += current) - current;

    while (current != 0 || next != 1)
    {
        v.push_back(current);
        int tmp=next;
        next = (current+next)%m;
        current = tmp;
    }

    return v;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    vector<int> v = pisano(m);
    std::cout << v[n % v.size()] << '\n';
}
