#include <stdio.h>
#include <stdlib.h>

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
    struct node *link;
};

typedef struct node *Node;

/* Function to get student data */
STU GetData()
{
    STU temp;

    printf("Enter USN: ");
    scanf(" %[^\n]", temp.usn);

    printf("Enter Name: ");
    scanf(" %[^\n]", temp.name);

    printf("Enter Branch: ");
    scanf(" %[^\n]", temp.branch);

    printf("Enter Semester: ");
    scanf("%d", &temp.sem);

    printf("Enter Phone Number: ");
    scanf(" %[^\n]", temp.phno);

    return temp;
}

/* Display one record */
void displayRec(STU ele)
{
    printf("%s\t%s\t%s\t%d\t%s\n",
           ele.usn, ele.name, ele.branch, ele.sem, ele.phno);
}

/* Create a node */
Node create(STU ele)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp->info = ele;
    temp->link = NULL;
    return temp;
}

/* Insert at front */
Node Finsert(Node first, STU ele)
{
    Node temp = create(ele);
    temp->link = first;
    return temp;
}

/* Insert at end */
Node Einsert(Node first, STU ele)
{
    Node temp = create(ele), cur;

    if (first == NULL)
        return temp;

    cur = first;
    while (cur->link != NULL)
        cur = cur->link;

    cur->link = temp;
    return first;
}

/* Display list */
void display(Node first)
{
    Node temp = first;

    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("\nUSN\tNAME\tBRANCH\tSEM\tPHONE\n");
    while (temp != NULL)
    {
        displayRec(temp->info);
        temp = temp->link;
    }
}

/* Count nodes */
int count(Node first)
{
    int c = 0;
    while (first != NULL)
    {
        c++;
        first = first->link;
    }
    return c;
}

/* Delete from front */
Node Fdelete(Node first)
{
    Node temp;

    if (first == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    temp = first;
    printf("Deleted Record:\n");
    displayRec(temp->info);

    first = first->link;
    free(temp);
    return first;
}

/* Delete from end */
Node Edelete(Node first)
{
    Node temp, prev;

    if (first == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (first->link == NULL)
    {
        printf("Deleted Record:\n");
        displayRec(first->info);
        free(first);
        return NULL;
    }

    prev = NULL;
    temp = first;
    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }

    printf("Deleted Record:\n");
    displayRec(temp->info);
    prev->link = NULL;
    free(temp);
    return first;
}

/* Main function */
int main()
{
    Node first = NULL;
    int choice;
    STU ele;

    while (1)
    {
        printf("\n--- MENU ---");
        printf("\n1. Insert Front");
        printf("\n2. Insert End");
        printf("\n3. Delete Front");
        printf("\n4. Delete End");
        printf("\n5. Display");
        printf("\n6. Count");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            ele = GetData();
            first = Finsert(first, ele);
            break;

        case 2:
            ele = GetData();
            first = Einsert(first, ele);
            break;

        case 3:
            first = Fdelete(first);
            break;

        case 4:
            first = Edelete(first);
            break;

        case 5:
            display(first);
            break;

        case 6:
            printf("Number of nodes = %d\n", count(first));
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
