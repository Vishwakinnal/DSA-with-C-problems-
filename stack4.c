#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef enum
{lprn,rprn,plus,minus,times,divide,mod,eos,operand}precedence;
char stack[MAX];
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
precedence getStackToken(char symbol) 
{ 
 switch(symbol) 
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
void push(char ele,int*top)
{
    stack[++(*top)]=ele;
}
char pop(int*top)
{
    char ele;
    ele=stack[(*top)--];
    return ele;
}
void convert(char*exprn,char*postfix)
{
    int n=0,i=0;
    precedence token;
    char symbol;
    int opr1,opr2;
    int top=-1;
    token=getToken(&symbol,&n);
    while(token!=eos)
    {
        switch(token)
        {
            case operand:
                postfix[i++]=symbol;
                break;
            case lprn:
                push(symbol,&top);
                break;
            case rprn:
                while(stack[top]!='(')
                {
                    postfix[i++]=pop(&top);
                }
                pop(&top);
                break;
            case plus:
            case minus:
            case times:
            case divide:
            case mod:
                if(top==-1)
                {
                    push(symbol,&top);
                }
                else
                {
                    while(top!=-1&&isp[getStackToken(stack[top])]>=icp[token])
                    {
                        postfix[i++]=pop(&top);
                    }
                    push(symbol,&top);
                }
                break;
        }
        token=getToken(&symbol,&n);
    }
    while(top!=-1)
    {
        postfix[i++]=pop(&top);
    }
    postfix[i]='\0';
}
int main()
{
    printf("enter the expression\n");
    scanf("%s",exprn);
    strcat(exprn,"#");
    convert(exprn,postfix);
    printf("after evaluation the postfix expression is %s\n",postfix);
}
