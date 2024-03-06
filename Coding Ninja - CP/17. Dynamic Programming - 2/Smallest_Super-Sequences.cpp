#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//RECURSIVE SOLUTION
// int helper(char str1[], int len1, char str2[], int len2, int **dp)
// {
//     if (len1 <= 0)
//     {
//         return len2;
//     }
//     if (len2 <= 0)
//     {
//         return len1;
//     }
//     if (len1 == 0 && len2 == 0)
//     {
//         return 0;
//     }
//     if (dp[len1][len2] > -1)
//     {
//         return dp[len1][len2];
//     }
//     int ans = 0;
//     if (str1[0] == str2[0])
//     {
//         ans = 1 + helper(str1 + 1, len1 - 1, str2 + 1, len2 - 1, dp);
//     }
//     else
//     {
//         int option1 = 1 + helper(str1 + 1, len1 - 1, str2, len2, dp);
//         int option2 = 1 + helper(str1, len1, str2 + 1, len2 - 1, dp);
//         ans = min(option1, option2);
//     }
//     dp[len1][len2] = ans;
//     return ans;
// }

// int smallestSuperSequence(char str1[], char str2[])
// {
//     int len1 = strlen(str1);
//     int len2 = strlen(str2);
//     int **dp = new int *[len1 + 1];
//     for (int i = 0; i <= len1; i++)
//     {
//         dp[i] = new int[len2 + 1];
//         for (int j = 0; j <= len2; j++)
//         {
//             dp[i][j] = -1;
//         }
//     }
//     return helper(str1, len1, str2, len2, dp);
// }

//ITERATIVE SOLUTION
int smallestSuperSequenceHelper(string s1, string s2, int m, int n, int **dp)
{
    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
            }
        }
    }

    return dp[0][0];
}

int smallestSuperSequence(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
    }
    int count = 0;
    for (int i = n; i >= 0; i--)
    {
        dp[m][i] = count++;
    }
    count = 0;
    for (int i = m; i >= 0; i--)
    {
        dp[i][n] = count++;
    }

    int ans = smallestSuperSequenceHelper(s1, s2, m - 1, n - 1, dp);
    return ans;
}

int main()
{
    char str1[50], str2[50];
    cin >> str1;
    cin >> str2;
    int min_len = smallestSuperSequence(str1, str2);
    cout << min_len;
    return 0;
}
