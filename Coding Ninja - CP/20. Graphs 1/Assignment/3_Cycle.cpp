#include <iostream>
#include <vector>
using namespace std;
int count_cycles(int **arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && arr[i][j] == 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if (j != k && k != i && arr[j][k] == 1)
                    {
                        if (arr[i][k] == 1)
                        {
                            count += 1;
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int f, s;
        cin >> f >> s;
        arr[f][s] = 1;
        arr[s][f] = 1;
    }

    cout << count_cycles(arr, n) / 6 << endl;
    return 0;
}