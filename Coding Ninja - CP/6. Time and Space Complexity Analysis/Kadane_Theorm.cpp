// Max_Sum_Subarray
#include <bits/stdc++.h>
using namespace std;
int Kadane(int *p, int n)
{
    int curr_sum = 0;
    int best_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + p[i];
        if (best_sum < curr_sum)
        {
            best_sum = curr_sum;
        }
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return best_sum;
}
int main()
{
    int n;
    cin >> n;
    int *p = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int result = Kadane(p, n);
    cout << result;
    delete[] p;
    return 0;
}