#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void linkedlistInsert(struct Node *ptr, int val)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        printf("Overflow condition");
        return;
    }
    p->data = val;
    p->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
}

struct Node *InsertAtFirst(struct Node *ptr, int val)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        printf("Overflow condition\n");
        return;
    }
    p->data = val;
    p->next = ptr;
    return p;
}

void InsertAtIndex(struct Node *ptr, int val, int indx)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        printf("Overflow condition\n");
        return;
    }
    p->data = val;
    int i = 1;
    while (i != indx)
    {
        ptr = ptr->next;
        i++;
    }
    p->next = ptr->next;
    ptr->next = p;
}

// Case 1: Deleting the first element from the linked list
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// Case 2: Deleting the element at a given index from the linked list
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}
// Case 3: Deleting the last element
struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 3;
    fourth->next = NULL;

    linkedlistTraversal(head);
    linkedlistInsert(head, 8);
    linkedlistTraversal(head);

    head = InsertAtFirst(head, 1);
    linkedlistTraversal(head);

    InsertAtIndex(head, 23, 3);
    linkedlistTraversal(head);

    printf("Linked list before deletion\n");
    linkedlistTraversal(head);
    // head = deleteFirst(head); // For deleting first element of the linked list
    // head = deleteAtIndex(head, 2);
    head = deleteAtLast(head);
    printf("Linked list after deletion\n");
    linkedlistTraversal(head);

    return 0;
}
