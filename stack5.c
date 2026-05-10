#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef enum
{lprn,rprn,plus,minus,times,divide,mod,eos,operand}precedence;
int stack[MAX];
char exprn[MAX],postfix[MAX];
static int isp[]={0,19,12,12,13,13,13,0};
static int icp[]={20,19,12,12,13,13,13,0};
precedence getToken(char*symbol,int*n)
{
    *symbol=exprn[(*n)++];
    switch(*symbol)
    {
        case '(': return lprn;
        case ')': return rprn;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '#': return eos;
        default: return operand;
    }
}
void push(int ele,int*top)
{
    stack[++(*top)]=ele;
}
int pop(int*top)
{
    int ele;
    ele=stack[(*top)--];
    return ele;
}
int eval()
{
    int n=0,j;
    precedence token;
    char symbol;
    int opr1,opr2;
    int top=-1;
    token=getToken(&symbol,&n);
    while(token!=eos)
    {
        if(token==operand)
        {
            push(symbol-'0',&top);
        }
        else
        {
            opr2=pop(&top);
            opr1=pop(&top);
            switch(token)
            {
                case plus:
                    push(opr1+opr2,&top);
                    break;
                case minus:
                    push(opr2-opr1,&top);
                    break;
                case times:
                    push(opr1*opr2,&top);
                    break;
                case mod:
                    push(opr1%opr2,&top);
                    break;
                case divide:
                    if(opr2!=0)
                    {
                        push(opr2/opr1,&top);
                    }
                    else
                    {
                        printf("division by zero\n");
                        exit(0);
                    }
                    break;
            }
        }
        for(j=0;j<=top;j++)
        {
            printf("stack[%d]=%d\n",j,stack[j]);
        }
        token=getToken(&symbol,&n);
    }
    return pop(&top); //important note here
}
int main()
{
    printf("enter the suffix expression\n");
    scanf("%s",exprn);
    strcat(exprn,"#");
    printf("The postfix expression is: %s\n",exprn);
    printf("after evaluation the exprression is %d",eval());
}