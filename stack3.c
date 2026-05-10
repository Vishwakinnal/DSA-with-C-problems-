#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct
{
    int key;
}element;
element stack[MAX];
int top = -1;
int isfull()
{
    return((top == MAX - 1)?1:0);
}
int isempty()
{
    return((top == -1)?1:0);
}
void push (int ele)
{
    stack[++top].key = ele;
}
int pop()
{
    return stack[top--].key;
}
void display()
{
    int i;
    if(isempty())
    {
        printf("stack is empty\n");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("element[%d] = %d\n", i, stack[i].key);
        }
    }
}
int main()
{
    int n=10,oldtop,OrgNum,num,ele,choice;
    int flag=1;
    int flag1;
    while(flag)
    {
        printf("\n menu driven program for stacks");
        printf("\n 1.push \n 2.pop \n 3.palindrom \n 4.display \n 5.exit");
        printf("\n enter your choice"); 
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(isfull())
                {
                    printf("stack overflow\n");
                }
                else
                {
                    printf("enter the element to be pushed\n");
                    scanf("%d",&ele);
                    push(ele);
                }
                break;
            case 2:
                if(isempty())
                {
                    printf("stack underflow\n");
                }
                else
                {
                    ele=pop();
                    printf("popped element is %d\n",ele);
                }
                break;
            case 3: 
                oldtop=top; 
                top=-1;
                printf("\n Enter a number\t"); 
                scanf("%d",&num); 
                OrgNum=num; 
                while(num!=0) 
                { 
                    push(num%10); 
                    num=num/10; 
                } 
                flag1=1; 
                num=OrgNum; 
                while(!isempty()) 
                { 
                    if(num%10!=pop())
                    { 
                        flag1=0; 
                    }
                    num=num/10; 
                } 
                if(flag1==0)
                {
                    printf("\n %d is not palindrom",OrgNum); 
                }
                else 
                {
                    printf("\n %d is palindrom",OrgNum); 
                }
                top=oldtop;
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                flag=0;
                break;
        }
    }
}