#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char usn[20];
    char name[20];  
    char branch[20];
    int sem;
    char phno[15];
};
typedef struct student STU;
struct node
{
    STU info;
    struct node*link;
};
typedef struct node*Node;
STU GetData() 
{
    STU temp;

    printf("Enter the USN of student:");
    scanf(" %[^\n]",temp.usn);

    printf("Enter the name of student: ");
    scanf(" %[^\n]",temp.name);

    printf("Enter the branch of student:");
    scanf(" %[^\n]",temp.branch);

    printf("Enter the semester of student: ");
    scanf("%d", &temp.sem);

    printf("Enter the phone number of student:");
    scanf(" %[^\n]",temp.phno);

    return temp;
}

void displayRec(STU ele) ///display one record
{
    printf("%s\t\t",ele.usn);
    printf("%s\t",ele.name);
    printf("%s\t",ele.branch);
    printf("%d\t",ele.sem);
    printf("%s\t",ele.phno);
}
Node create(STU ele)//create a node
{
    Node temp;
    temp=(Node)malloc(sizeof(struct node));
    temp->info=ele;
    temp->link=NULL;
    return temp;
}
Node Finsert(Node first,STU ele) //insert at front
{
    Node temp=create(ele);
    if(first==NULL)
    {
        first=temp;
    }
    else
    {
        temp->link=first;
        first=temp;
    }
    return first;
}
Node Einsert(Node first,STU ele) // insert at end
{
    Node temp=create(ele),cur;
    if(first==NULL)
    {
        first=temp;
    }
    else
    {
        cur=first;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=temp;
    }
    return first;
}
void display(Node first)//display list
{
    Node temp=first;
    if(temp==NULL)
    {
        printf("lint is empty\n");
    }
    else
    {
        printf("students details\n");
        printf("USN\tNAME\tBRANCH\tSEM\tPHONE NUMBER\n");
        while(temp!=NULL)
        {
            displayRec(temp->info);
            temp=temp->link;
        }
    }
    return;
}
int count(Node first) //count nodes
{
    Node temp=first;
    int count=0;
    if(temp==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            count ++;
            temp=temp->link;
        }
    }
    return count;
}
Node Fdelete(Node first) //delete from front
{
    Node temp=first;
    if(temp==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp=first;
        printf("deleted student details\n");
        printf("USN\tNAME\tBRANCH\tSEM\tPHONE NUMBER\n");
        displayRec(temp->info);
        first=first->link;
        free(temp);
    }
    return first;
}
Node Edelete(Node first) //delete from end
{
    Node temp = first, t;
    if(temp==NULL)
    {
        printf("list is empty\n");
    }
    else if(first->link==NULL)
    {
        printf("deleted student details\n");
        printf("USN\tNAME\tBRANCH\tSEM\tPHONE NUMBER\n");
        displayRec(first->info);
        free(first);
        first=NULL;
    }
    else
    {
        while(temp->link->link!=NULL)
        {
            temp=temp->link;
        }
        printf("deleted student details\n");
        printf("USN\tNAME\tBRANCH\tSEM\tPHONE NUMBER\n");
        displayRec(temp->link->info);
        t=temp->link;
        temp->link=NULL;
        free(t);
    }
    return first;
}
int main() //   main function
{
    Node first=NULL;
    int choice,flag=1;
    STU ele;
    while(flag)
    {
        printf("\n menu driven program for linked list");
        printf("\n 1.insert at front \n 2.insert at end \n 3.delete from front \n 4.delete from end \n 5.display \n 6.count \n 7.exit");
        printf("\n enter your choice"); 
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                ele=GetData();
                first=Finsert(first,ele);
                break;
            case 2:
                ele=GetData();
                first=Einsert(first,ele);
                break;
            case 3:
                first=Fdelete(first);
                break;
            case 4:
                first=Edelete(first);
                break;
            case 5:
                display(first);
                break;
            case 6:
                printf("number of nodes in the list is %d\n",count(first));
                break;
            case 7:
                exit(0);
                break;
            default:
                flag=0;
                break;
        }
    }
}