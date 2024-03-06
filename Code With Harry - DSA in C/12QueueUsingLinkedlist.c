#include<stdio.h>
#include<stdlib.h>

struct Node *f=NULL;
struct Node *r=NULL;

struct Node{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr){
    if(ptr==NULL){
        printf("queue is Empty\n");
        return;
    }
    printf("The element in queue are :\n");
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}

void enqueue(int val){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("queue is Full\n");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int dequeue(){
    int val=-1;
    struct Node *ptr=f;
    if(f==NULL){
        printf("queue is Empty \n");
    }
    else{
        val=ptr->data;
        f=f->next;
        free(ptr);
    }
    return val;
}

int main(){
    linkedlisttraversal(f);
    printf("Dequeuing element %d\n",dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    linkedlisttraversal(f);
 return 0;
}