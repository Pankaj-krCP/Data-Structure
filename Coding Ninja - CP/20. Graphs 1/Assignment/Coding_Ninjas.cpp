#include <bits/stdc++.h>
using namespace std;

bool check(char **arr, bool **visited, string s, int n, int m, int i, int j)
{
    if (s.length() == 0)
    {
        return true;
    }
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return false;
    }
    int row_array[] = {i - 1, i, i + 1};
    int col_array[] = {j - 1, j, j + 1};
    for (int p = 0; p < 3; p++)
    {
        for (int q = 0; q < 3; q++)
        {
            if (row_array[p] == i && col_array[q] == j)
            {
                continue;
            }

            int row = row_array[p];
            int col = col_array[q];
            if (row < 0 || col < 0 || row >= n || col >= m)
            {
                continue;
            }
            if (arr[row][col] == s[0] && !visited[row][col])
            {
                visited[row][col] = true;
                bool checked = check(arr, visited, s.substr(1), n, m, row, col);
                if (checked)
                {
                    return checked;
                }
                else
                {
                    visited[row][col] = false;
                }
            }
        }
    }
    return false;
}


// bool check(char **arr, bool **visited, string str, int n, int m, int i, int j)
// {
//     if (str.length() == 0)
//     {
//         return true;
//     }

//     if (i < 0 || j < 0 || i >= n || j >= m)
//     {
//         return false;
//     }

//     if ((i - 1 >= 0 && j - 1 >= 0) && !visited[i - 1][j - 1] && arr[i - 1][j - 1] == str[0])
//     {
//         visited[i - 1][j - 1] = true;
//         if (check(arr, visited, str.substr(1), n, m, i - 1, j - 1))
//         {
//             return true;
//         }
//         visited[i - 1][j - 1] = false;
//     }

//     if ((i - 1 >= 0 && j >= 0) && !visited[i - 1][j] && arr[i - 1][j] == str[0])
//     {
//         visited[i - 1][j] = true;
//         if (check(arr, visited, str.substr(1), n, m, i - 1, j))
//         {
//             return true;
//         }
//         visited[i - 1][j] = false;
//     }

//     if ((i - 1 >= 0 && j + 1 < m) && !visited[i - 1][j + 1] && arr[i - 1][j + 1] == str[0])
//     {
//         visited[i - 1][j + 1] = true;
//         if (check(arr, visited, str.substr(1), n, m, i - 1, j + 1))
//         {
//             return true;
//         }
//         visited[i - 1][j + 1] = false;
//     }

//     if ((i >= 0 && j - 1 >= 0) && !visited[i][j - 1] && arr[i][j - 1] == str[0])
//     {
//         visited[i][j - 1] = true;
//         if (check(arr, visited, str.substr(1), n, m, i, j - 1))
//         {
//             return true;
//         }
//         visited[i][j - 1] = false;
//     }

//     if ((i >= 0 && j + 1 < m) && !visited[i][j + 1] && arr[i][j + 1] == str[0])
//     {
//         visited[i][j + 1] = true;
//         if (check(arr, visited, str.substr(1), n, m, i, j + 1))
//         {
//             return true;
//         }
//         visited[i][j + 1] = false;
//     }

//     if ((i + 1 < n && j - 1 >= 0) && !visited[i + 1][j - 1] && arr[i + 1][j - 1] == str[0])
//     {
//         visited[i + 1][j - 1] = true;
//         if (check(arr, visited, str.substr(1), n, m, i + 1, j - 1))
//         {
//             return true;
//         }
//         visited[i + 1][j - 1] = false;
//     }

//     if ((i + 1 < n && j >= 0) && !visited[i + 1][j] && arr[i + 1][j] == str[0])
//     {
//         visited[i + 1][j] = true;
//         if (check(arr, visited, str.substr(1), n, m, i + 1, j))
//         {
//             return true;
//         }
//         visited[i + 1][j] = false;
//     }

//     if ((i + 1 < n && j + 1 < m) && !visited[i + 1][j + 1] && arr[i + 1][j + 1] == str[0])
//     {
//         visited[i + 1][j + 1] = true;
//         if (check(arr, visited, str.substr(1), n, m, i + 1, j + 1))
//         {
//             return true;
//         }
//         visited[i + 1][j + 1] = false;
//     }

//     return false;
// }


int main()
{
    int n, m;
    cin >> n >> m;
    char **arr = new char *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m];
    }

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j];
        }
    }

    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    string s = "CODINGNINJA";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'C')
            {
                visited[i][j] = true;
                if (check(arr, visited, s.substr(1), n, m, i, j))
                {
                    cout << "string found" << endl;
                    return 0;
                }
                visited[i][j] = false;
            }
        }
    }

    cout << "no matching string found" << endl;

    return 0;
}