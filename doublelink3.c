#include<stdio.h>
#include<stdlib.h>
struct employee
{
    char ssn[12];
    char name[20];
    char branch[20];
    char des[20];
    char salary[10];
    char phno[15];
};
typedef struct employee EMP;
struct node
{
    EMP info;
    struct node*lptr;
    struct node* rptr;
};
typedef struct node* Node;
Node front=NULL,rear=NULL;
EMP GetRec()
{
    EMP temp;
    printf("Enter the SSN of employee:");
    scanf(" %[^\n]",&temp.ssn);
    printf("Enter the name of employee: ");
    scanf(" %[^\n]",&temp.name);
    printf("Enter the branch of employee:");
    scanf(" %[^\n]",&temp.branch);
    printf("Enter the designation of employee: ");
    scanf(" %[^\n]",temp.des);
    printf("Enter the salary of employee:");
    scanf(" %[^\n]",&temp.salary);
    printf("Enter the phone number of employee:");
    scanf(" %[^\n]",&temp.phno);
    return temp;
}
void displayRec(EMP temp)
{
    printf("%s\t\t",temp.ssn);
    printf("%s\t",temp.name);
    printf("%s\t",temp.branch);
    printf("%s\t",temp.des);
    printf("%s\t",temp.salary);
    printf("%s\t",temp.phno);
}
Node create(EMP ele)
{
    Node temp;
    temp=(Node)malloc(sizeof(struct node));
    temp->info=ele;
    temp->lptr=NULL;
    temp->rptr=NULL;
    return temp;
}
void Finsert(EMP ele)
{
    Node temp=create(ele);
    if(front==NULL)
    {
        front=rear=temp;
    }
    else
    {
        temp->rptr=front;
        front->lptr=temp;
        front=temp;
    }
}
void Einsert(EMP ele)
{
    Node temp=create(ele);
    if(rear==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->rptr=temp;
        temp->lptr=rear;
        rear=temp;
    }
}
void Fdelete()
{
    Node temp=front;
    if(front==NULL)
    {
        printf("list is empty\n");

    }
    else
    {
        temp=front;
        printf("deleted employee details\n");
        printf("SSN\tNAME\tBRANCH\tDESIGNATION\tSALARY\tPHONE NUMBER\n");
        displayRec(temp->info);
        front=front->rptr;
        if(front!=NULL)
        {
            front->lptr=NULL;
        }
        else
        {
            rear=NULL;
        }
        free(temp);
    }
}
void Edelete()
{
    Node temp=rear;
    if(rear==NULL)
    {
        printf("list is empty\n");
    }
    else if(rear->lptr==NULL)
    {
        printf("deleted employee details\n");
        printf("SSN\tNAME\tBRANCH\tDESIGNATION\tSALARY\tPHONE NUMBER\n");
        displayRec(rear->info);
        front=NULL;
        rear=NULL;
        free(temp);
    }
    else
    {
        rear=rear->lptr;
        rear->rptr=NULL;
        printf("deleted employee details\n");
        printf("SSN\tNAME\tBRANCH\tDESIGNATION\tSALARY\tPHONE NUMBER\n");
        displayRec(temp->info);
        free(temp);
    }
}
void display()
{
    Node temp=front;
    if(temp==NULL)  
    {
        printf("list is empty\n");
    }
    else
    {
        printf("SSN\tNAME\tBRANCH\tDESIGNATION\tSALARY\tPHONE NUMBER\n");
        while(temp!=NULL)
        {
            displayRec(temp->info);
            temp=temp->rptr;
        }

    }
}
int main()
{   
    int choice,flag=1;
    EMP ele;
    while(flag)
    {
        printf("\n Menu driven program for double linked list\n");
        printf("1. Insert at front\n2. Insert at end\n3. Delete from front\n4. Delete from end\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                ele=GetRec();
                Finsert(ele);
                break;
            case 2:
                ele=GetRec();
                Einsert(ele);
                break;
            case 3:
                Fdelete();
                break;
            case 4:
                Edelete();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                flag=0;
                break;
        }
    }
}
