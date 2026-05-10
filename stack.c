#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top= -1;

int isFULL()
{
    if(top == MAX -1)
        return 1;
    else
        return 0;
}

int isEMPTY()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
void push(int data)
{
    if(isFULL())
    {
        printf("STACK IS OVERFLOW\n");
        return;
    }
    top =top +1;
    stack_arr[top]=data;
    
}
int pop()
{
    if(isEMPTY())
    {
        printf("STACK IS UNDERFLOW\n");
        exit(1);
    }
    int data = stack_arr[top];
    top= top-1;
    return data;
}

int peek()
{
    if(isEMPTY())
    {
        printf("stack isEMPTY\n");
        exit(1);
    }
    return stack_arr[top];
}

void print()
{
    if(isEMPTY())
    {
        printf("stack isEMPTY\n");
        return;
    }
    int i;
    for( i=top; i>=0 ; i++)
    {
        printf("%d", stack_arr[i]);
        printf("\n");

    }
}
int main()
{
    int choice,data;
    while(1)
    {
        printf("1.push\n2.pop\n3.peek\n4.print\n5.exit\n");
        printf("enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("enter data to push : ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                printf("poped element is %d\n", pop());
                break;
            case 3:
                printf("top element is %d\n", peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}