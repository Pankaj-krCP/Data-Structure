#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k;
    int B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergesort(int A[], int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergesort(A, 0, 6);
    printArray(A, n);
    return 0;
}