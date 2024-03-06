#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

int LinearSearch(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    struct Array arr = {{2, 4, 6, 8, 23, 56}, 10, 6};
    printf("%d\n", BinarySearch(arr, 9));
    printf("%d\n", LinearSearch(arr, 6));

    return 0;
}