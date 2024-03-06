/*
Quick Sort Code
Send Feedback
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end)
{
    int count = 0;
    int pivot = arr[start];
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int piovtindex = start + count;
    int temp = arr[start];
    arr[start] = arr[piovtindex];
    arr[piovtindex] = temp;

    int i = start, j = end;
    while (i <= piovtindex && j >= piovtindex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] >= pivot)
        {
            j--;
        }
        if (i < piovtindex && j > piovtindex)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return piovtindex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int c = partition(arr, start, end);
    quickSort(arr, start, c - 1);
    quickSort(arr, c + 1, end);
}

int main()
{
    int n;
    cin >> n;

    int input[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}