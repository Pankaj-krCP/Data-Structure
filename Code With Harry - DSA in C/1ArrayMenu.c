#include <stdio.h>
struct Array
{
    int *A;
    int size;
    int length;
};

void Append(struct Array *arr1, int x)
{
    if (arr1->length < arr1->size)
    {
        arr1->A[arr1->length++] = x;
    }
}

void Insert(struct Array *arr1, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr1->length)
    {
        for (i = arr1->length; i > index; i--)
            arr1->A[i] = arr1->A[i - 1];
        arr1->A[index] = x;
        arr1->length++;
    }
}

int Delete(struct Array *arr1, int index)
{
    int x = 0, i;
    if (index >= 0 && index < arr1->length)
    {
        x = arr1->A[index];
        for (i = index; i < (arr1->length - 1); i++)
            arr1->A[i] = arr1->A[i + 1];
        arr1->length--;
        return x;
    }
    return 0;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
            return i;
    }
    return -1;
}

int Sum(struct Array arr)
{
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++)
        s += arr.A[i];

    return s;
}

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

int main()
{
    struct Array arr1;
    int ch;
    int x, index;

    printf("Enter size of Array\n");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;

    do
    {
        printf("\n\n Menu\n1.Append\n2.Insert\n3.Delete\n4.Search\n5.Sum\n6.Display\n7.Exit\n");
        printf("enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("enter element to Append\n");
            scanf("%d", &x);
            Append(&arr1, x);
            break;
        case 2:
            printf("Enter an element and index\n");
            scanf("%d%d", &x, &index);
            Insert(&arr1, index, x);
            break;
        case 3:
            printf("Enter index to delete\n");
            scanf("%d", &index);
            x = Delete(&arr1, index);
            printf("deleted element is %d ", x);
            break;
        case 4:
            printf("Enter element to search\n");
            scanf("%d", &x);
            index = LinearSearch(&arr1, x);
            printf("Element index %d ", index);
            break;
        case 5:
            printf("Sum is %d\n", Sum(arr1));
            break;
        case 6:
            Display(arr1);
        }
    } while (ch < 7);
    return 0;
}