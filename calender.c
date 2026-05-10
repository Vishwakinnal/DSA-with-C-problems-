#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
    char *name;        // dynamically allocated string for day name
    int date;          // integer for date
    char *activity;    // dynamically allocated string for activity
};

struct Day *calendar;   // pointer to dynamically created array of 7 days

// Function to create calendar (allocate memory)
void create() {
    calendar = (struct Day *)malloc(7 * sizeof(struct Day));
    if (calendar == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Function to read data from keyboard
void read() {
    char temp[100];   // temporary buffer for input
    for (int i = 0; i < 7; i++) {
        printf("\nEnter details for Day %d:\n", i + 1);

        // Day name
        printf("Day Name: ");
        scanf("%[^\n]s", temp);
        calendar[i].name = (char *)malloc(strlen(temp) + 1);
        strcpy(calendar[i].name, temp);

        // Date
        printf("Date (number): ");
        scanf("%d", &calendar[i].date);

        // Activity
        printf("Activity: ");
        scanf(" %[^\n]s", temp);
        calendar[i].activity = (char *)malloc(strlen(temp) + 1);
        strcpy(calendar[i].activity, temp);
    }
}

// Function to display week’s activity report
void display() {
    printf("\n--- Weekly Activity Report ---\n");
    for (int i = 0; i < 7; i++) {
        printf("\nDay: %s\n", calendar[i].name);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].activity);
    }
}

// Main function
int main() {
    create();    // allocate memory for 7 days
    read();      // take input from user
    display();   // show report

    // Free allocated memory
    for (int i = 0; i < 7; i++) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }
    free(calendar);

    return 0;
}