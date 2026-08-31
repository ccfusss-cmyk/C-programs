#include<stdio.h>
#define SIZE 100
int queue[SIZE];
int front=-1,rear=-1;

void enqueue()
{
    int value;
    printf("enter value to enqueue");
    scanf("%d",&value);
    if(rear==SIZE-1)
        printf("queue overflow\n");
    else
    {
        rear++;
        queue[rear]=value;
    }
}

void dequeue()
{
    if(front==rear)
        printf("queue underflow\n");
    else
    {
        front++;
        printf("dequeue %d \n",queue[front]);
    }
}

void display()
{
    if(front==rear)
        printf("queue is empty\n");
    else
    {
        printf("queue elements:");
        for(int i=front+1;i<=rear;i++)
            printf("%d",queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice,value;
    printf("\n***MENU***\n");
    printf("1.enqueue\n");
    printf("2.dequeue\n");
    printf("3.display\n");
    printf("4.exit\n");
    while(1)
    {
        printf("enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("exit program\n");
                    return 0;
            default: printf("invalid choice! pls try again\n");
        }
    }
    return 0;
}
