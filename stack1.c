#include<stdio.h> 
#include<stdlib.h> 
#define STACK_SIZE 10 
typedef struct 
{ 
    int key; 
}element; 
element Stack[STACK_SIZE]; 
int top = -1; 
int IsEmpty() 
{ 
    return ((top == -1)? 1 : 0); 
} 
int IsFull() 
{ 
    return ((top >= STACK_SIZE - 1)? 1 : 0); 
} 
void push(int ele) 
{ 
    if(IsFull())  
        printf("\nStack Full"); 
    else 
        Stack[++top].key=ele; 
} 
int pop() 
{ 
    if(IsEmpty()) 
    { 
        printf("\nStack Empty"); 
        return -1;
    } 
    else 
        return(Stack[top--].key); 
} 
void display() 
{ 
int i; 
if(IsEmpty()) 
    printf("\n Stack is Empty\n"); 
else 
{ 
    printf("\n Elements of Stack\t"); 
    for(i=top;i>=0;i--) 
        printf("\t%d",Stack[i].key); 
} 
} 
void main() 
{ 
    int n=10,i,oldTop,num,OrgNum,ele; 
    int ch,flag=1; 
    int flag1; 
    while(flag) 
    { 
        printf("\n Menu Driven Program\n"); 
        printf("\n1 Push\n2 Pop\n3 Palindrom\n4 Display\n5 Exit\n"); 
        printf("\nEnter the Choice\t"); 
        scanf("%d",&ch); 
        switch(ch) 
        { 
        case 1: 
            printf("\nEnter the Element to push\t"); 
            scanf("%d",&ele); 
            push(ele); 
            break; 
        case 2: 
            ele=pop(); 
            if(ele!=-1) 
                printf("\n The Element Poped is %d",ele); 
                break; 
        case 3: 
            oldTop=top; 
            top=-1; 
            printf("\n Enter a number\t"); 
            scanf("%5d",&num); 
            OrgNum=num; 
            while(num!=0) 
            { 
                push(num%10); 
                num=num/10; 
            } 
            flag1=1; 
            num=OrgNum; 
            while(!IsEmpty()) 
            { 
                if(num%10 != pop()) 
                    flag1=0; 
                num=num/10; 
            } 
            if(flag1==0) 
                printf("\n %d is not palindrom",OrgNum); 
            else 
                printf("\n %d is palindrom",OrgNum); 
                top=-1; 
                break; 
        case 4: 
            display(); 
            break; 
        case 5: 
            default : flag=0; 
            printf("\n Exiting...."); 
            break;
        } 
    } 
}