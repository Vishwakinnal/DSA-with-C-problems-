#include<stdio.h>
#define MAX 100
int queue[MAX],front=-1,rear=-1;
void enqueue(int value)
{
    if(rear==MAX-1)
    {
        printf("queue is full");

    }
    else
    {
        if(front=-1)
        {
            front=0;
            rear=rear+1;
            queue[rear]=value;
            printf("inserted element is %d\n",value);
        }
    }
}
void dequeue()
{
    int value;
    if(front==-1)
    {
        printf("queue is empty");
    }
    else
    {
        value=queue[front];
        front=front+1;
        printf("deleted element is %d\n",value);

    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("elements in queue are \n");
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
int main()
{
    enqueue(10);
    enqueue(20);        
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();

    display();
    return 0;
}