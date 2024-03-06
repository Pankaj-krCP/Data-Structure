#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

//sorting on value/weight
bool compare(Item a, Item b)
{
    double ans1 = ((double)a.value / a.weight);
    double ans2 = ((double)b.value / b.weight);
    return ans1 > ans2;
}

double knapsack(Item *arr, int n, int w)
{
    sort(arr, arr + n, compare);
    int curr_w = 0;
    double val = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr_w + arr[i].weight <= w)
        {
            curr_w += arr[i].weight;
            val += arr[i].value;
        }
        else
        {
            int rem = w - curr_w;
            val += ((double)rem / arr[i].weight) * arr[i].value; // ( rem weight/current item weight ) * current value
            curr_w = w;
            break;
        }
    }
    return val;
}

int main()
{
    int w = 70;
    Item arr[] = {{60, 20}, {70, 15}, {80, 40}};
    cout << knapsack(arr, 3, w) << endl;
    return 0;
}
