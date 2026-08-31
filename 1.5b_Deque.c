#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5

int arr[CAPACITY];
int front=0;
int rear=0;
int size=0;

int isFull()
{
    return size==CAPACITY;
}

int isEmpty()
{
    return size==0;
}

void insertFront(int value)
{
    if (isFull())
    {
        printf("deque is full\n");
        return;
    }
    front=(front+1)%CAPACITY;
    arr[front]=value;
    size++;
}

void insertRear(int value)
{
    if (isFull())
    {
        printf("deque is full\n");
        return;
    }
    arr[rear]=value;
    rear=(rear+1)%CAPACITY;
    size++;
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("deque is empty\n");
        return;
    }
    front=(front+1)%CAPACITY;
    size--;
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("deque is empty\n");
        return;
    }
    rear=(rear-1+CAPACITY)%CAPACITY;
    size--;
}

void displayDequeue()
{
    if (isEmpty())
    {
        printf("deque is empty\n");
        return;
    }
    printf("deque contents");
    int i=front;
    for(int count=0;count<size;count++)
    {
        printf("%d",arr[i]);
        i=(i+1)%CAPACITY;
    }
    printf("\n");
}

int main()
{
    int choice,item;
    printf("\n***Deque menu***\n");
    printf("1.insert at front\n");
    printf("2.insert at rear\n");
    printf("3.delete from front\n");
    printf("4.delete from rear\n");
    printf("5.display\n");
    printf("6.exit\n");

    while(1)
    {
        printf("enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("insert item to insert at front");
                scanf("%d",&item);
                insertFront(item);
                break;
            case 2:
                printf("enter item to insert at rear");
                scanf("%d",&item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                displayDequeue();
                break;
            case 6:
                printf("exiting program\n");
                exit(0);
            default:
                printf("invalid choice! pls try again\n");
        }
    }
    return 0;
}
