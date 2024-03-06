#include <iostream>
using namespace std;
int count_ones(int **arr, int n, int i, int j, bool **visited)
{
    int count = 1;
    if (i > 0 && !visited[i - 1][j] && arr[i - 1][j] == 1) //up
    {
        visited[i - 1][j] = true;
        count += count_ones(arr, n, i - 1, j, visited);
    }
    if (j > 0 && !visited[i][j - 1] && arr[i][j - 1] == 1) //left
    {
        visited[i][j - 1] = true;
        count += count_ones(arr, n, i, j - 1, visited);
    }
    if (i < n - 1 && !visited[i + 1][j] && arr[i + 1][j] == 1) //down
    {
        visited[i + 1][j] = true;
        count += count_ones(arr, n, i + 1, j, visited);
    }
    if (j < n - 1 && !visited[i][j + 1] && arr[i][j + 1] == 1) //right
    {
        visited[i][j + 1] = true;
        count += count_ones(arr, n, i, j + 1, visited);
    }
    return count;
}

int solve(int n, int **arr)
{
    int maximum = 0;
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                visited[i][j] = true;
                int current_maximum = count_ones(arr, n, i, j, visited);
                if (current_maximum > maximum)
                {
                    maximum = current_maximum;
                }
            }
        }
    }
    return maximum;
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << solve(n, arr);
    return 0;
}