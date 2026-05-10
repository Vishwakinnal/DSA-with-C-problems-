#include<stdio.h>
int main()
{
    int seen[10]={0};  //part=1
    int N;
    printf("Enter the number : ");
    scanf("%d", &N);

    int rem;   //part=2
    while(N>0)
    {
        rem=N % 10;
        if(seen [rem]==1) 
        
            break;
        
        seen[rem]=1;
        N=N/10;

    }
    if(N>0)   //part=3
        printf("yes");
    else
        printf("no");
    return 0;


}
