#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int d;
    cin >> d;
    int num = n - 1;
    int *arr = new int[d];
    int index = d;
    d--;
    arr[0] = 1;
    int rem = num % 9;
    int div = num / 9;

    if (div > 0)
    {
        while (div != 0)
        {
            arr[d] = 9;
            div--;
            d--;
        }
        arr[d--] = rem;
        while (d != 0)
        {
            arr[d--] = 0;
        }
    }
    else
    {
        arr[d--] = rem;
        while (d != 0)
        {
            arr[d--] = 0;
        }
    }

    for (int i = 0; i < index; i++)
    {
        cout << arr[i];
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// void winLottery(int sum, int n)
// {
//     int *arr = new int[n];
//     memset(arr, 0, sizeof(arr));
//     arr[0] = 1;
//     sum = sum - 1;
//     for (int i = n - 1; i >= 1; i--)
//     {
//         if (sum > 9)
//         {
//             arr[i] = 9;
//             sum = sum - 9;
//         }
//         else
//         {
//             arr[i] = sum;
//             sum = 0;
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i];
//     }
// }
// int main()
// {
//     int s, d;
//     cin >> s >> d;
//     winLottery(s, d);
// }
