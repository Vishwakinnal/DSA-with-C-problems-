#include <stdio.h>
#include <stdlib.h>

struct Day
{
    char *dayName;      // dynamically allocated string
    int date;           // integer date
    char *activity;     // dynamically allocated string
};

struct Day *calendar;   // dynamic array for 7 days

void create()
{
    calendar =(struct Day*) malloc(7 * sizeof(struct Day));

    for (int i = 0; i < 7; i++)
    {
        calendar[i].dayName = (char *)malloc(20 * sizeof(char));
        calendar[i].activity = (char *)malloc(50 * sizeof(char));
    }
}

void read()
{
    for (int i = 0; i < 7; i++)
    {
        printf("\nEnter details for Day %d\n", i + 1);

        printf("Day Name: ");
        scanf("%s", calendar[i].dayName);

        printf("Date: ");
        scanf("%d", &calendar[i].date);

        printf("Activity: ");
        scanf("%s", calendar[i].activity);
    }
}

void display()
{
    printf("\nWEEK ACTIVITY DETAILS\n");
    
    printf("----------------------\n");
    printf("Day \t\tDate \t\tActivity\n");

    for (int i = 0; i < 7; i++)
    {
        printf("%s\t\t%d\t\t%s\n",
               calendar[i].dayName,
               calendar[i].date,
               calendar[i].activity);
        
    }
}

int main()
{
    create();
    read();
    display();
    return 0;
}
