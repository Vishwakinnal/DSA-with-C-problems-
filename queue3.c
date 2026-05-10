#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct 
{
    int key;
}element;
element queue[MAX];
int front=-1;
int rear=-1;
int count=0;
int Qfull()
{
    return(count==MAX);
}
int Qempty()
{
    return(count==0);
}
void insert(int ele)
{
    rear=(rear+1)%MAX;
    if(Qfull())
    {
        printf("queue overflow\n");
    }
    if(front=-1)
    {
        front=0;
    }
    count++;
    queue[rear].key=ele;
}
int deleteq()
{
    int ret;
    if(Qempty())
    {
        printf("queue is empty\n");
        return -1;
    }
    ret=queue[front].key;
    front=front+1%MAX;
    count--;
    return ret;
}
void display()
{
    int i,j;
    if(Qempty())
    {
        printf("queue is empty\n");
    }
    else
    {
        j=front;
        printf("elements in queue is \n");
        for(i=0;i<count;i++)
        {
            printf("queue[%d]=%d\n",j,queue[j].key);
            j=(j+1)%MAX;
        }
    }
}
int main()
{
    int n=10,ele,choice,flag=1;
    while(flag)
    {
        printf("\n menu driven program for circular queue\n");
        printf("\n1.insert \n 2.deleteq \n 3.display \n 4.exit \n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(Qfull())
                {
                    printf("queue is full");
                }
                else
                {
                    printf("enter the number to insert:");
                    scanf("%d",&ele);
                    insert(ele);
                }
                break;
            case 2:
                if(Qempty())
                {
                    printf("queue is empty\n");
                }
                else
                {
                    ele=deleteq();
                    printf("deleted element is %d\n",ele);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                flag=0;
                break;
            
        }
    }
}
