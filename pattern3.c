#include <stdio.h>

#define MAX 100

void findReplace(char str[], char pat[], char rep[])
{
    char result[MAX];
    int i = 0, j = 0, k;
    int found = 0;

    
    while (str[i] != '\0')
    {
        k = 0;

        while (pat[k] != '\0' && str[i + k] == pat[k])
            k++;

        if (pat[k] == '\0')   // Pattern matched
        {
            found = 1;

            int m = 0;
            while (rep[m] != '\0')
                result[j++] = rep[m++];

            i += k;
        }
        else
        {
            result[j++] = str[i++];
        }
    }

    result[j] = '\0';

    if (found)
        printf("\nResultant String: %s", result);
    else
        printf("\nPattern not found");
}

int main()
{
    char STR[MAX], PAT[MAX], REP[MAX];

    printf("Enter Main String: ");
    scanf(" %[^\n]",STR);

    printf("Enter Pattern: ");
    scanf(" %[^\n]",PAT);

    printf("Enter Replace String: ");
    scanf(" %[^\n]",REP);

    findReplace(STR,PAT,REP);

    return 0;
}
