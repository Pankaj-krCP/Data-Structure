#include <iostream>
using namespace std;

int countPalindromeSubstrings(char s[])
{
    // Write your code here
    // int n = sizeof(s)/sizeof(char);
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int left = i;
        int right = i;
        while ((left >= 0 && right < n) && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }

        left = i;
        right = i + 1;
        while ((left >= 0 && right < n) && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
    }

    return count;
}

int main()
{
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}
