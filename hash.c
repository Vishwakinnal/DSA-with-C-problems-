#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

/* Insert key into hash table using linear probing */
void insert(int key)
{
    int index, i; 
    index = key % SIZE;
    if (hashTable[index] == -1) //check if empty
    {
        hashTable[index] = key;  //insert key
    }
    else
    {
        for (i = 1; i < SIZE; i++)  //collision occurs
        {
            index = (key % SIZE + i) % SIZE;

            if (hashTable[index] == -1) //find next empty slot
            {
                hashTable[index] = key;
                break;
            }
        }
    }
}

/* Display hash table */
void display()
{
    int i;
    printf("\nHash Table:\n");  //header and table
    printf("Index\tKey\n");

    for (i = 0; i < SIZE; i++)  // traverse 
    {
        if (hashTable[i] != -1) //insert
            printf("%d\t%d\n", i, hashTable[i]);
        else
            printf("%d\t--\n", i);
    }
}

int main()
{
    int i, n, key;

    /* Initialize hash table */
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter 4-digit employee keys:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
