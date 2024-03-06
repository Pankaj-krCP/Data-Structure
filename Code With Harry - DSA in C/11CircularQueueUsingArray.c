#include<stdio.h>
#include<stdlib.h>

struct circularqueue{
    int size;
    int r;
    int f;
    int *arr;
};

int isEmpty(struct circularqueue *cq){
    if(cq->r==cq->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct circularqueue *cq){
    if((cq->r+1)%cq->size==cq->f){
        return 1;
    }
    else return 0;
}

void enqueue(struct circularqueue *cq,int val){
    if(isFull(cq)){
        printf("Circularqueue is full \n ");
        return;
    }
    else{
        cq->r=(cq->r+1)%cq->size;
        cq->arr[cq->r]=val;
        printf("Enqueue Element is %d \n",val);
    }
}

int dequeue(struct circularqueue *cq){
    int a=-1;
    if(isEmpty(cq)){
        printf("CircularQueue Is Empty \n");
    }
    else{
        cq->f=(cq->f+1)%cq->size;
        a=cq->arr[cq->f];
    }
    return a;
}

int main(){
    struct circularqueue cq;
    cq.size=4;
    cq.r=cq.f=0;
    cq.arr=(int *)malloc(cq.size*sizeof(int));
    enqueue(&cq, 12);
    enqueue(&cq, 15);
    enqueue(&cq, 1); 
    printf("Dequeuing element %d\n", dequeue(&cq));
    printf("Dequeuing element %d\n", dequeue(&cq));
    printf("Dequeuing element %d\n", dequeue(&cq)); 
    enqueue(&cq, 45);
    enqueue(&cq, 45);
    enqueue(&cq, 45);
    if(isEmpty(&cq)){
        printf("Queue is empty\n"); 
    }
    if(isFull(&cq)){
        printf("Queue is full\n");
    }
    return 0;
}