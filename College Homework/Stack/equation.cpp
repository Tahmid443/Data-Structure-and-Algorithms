//[1+2*{3+4*(5+6)+(3+2)}]
#include <bits/stdc++.h>
using namespace std;

// Stack for numbers
int valStack[100];
int valueTop = -1;

// Stack for operators
char opStack[100];
int opTop = -1;

// Push number
void pushValue(int x)
{
    valStack[++valueTop] = x;
}

// Pop number
int popValue()
{
    return valStack[valueTop--];
}

// Push operator
void pushOp(char ch)
{
    opStack[++opTop] = ch;
}

// Pop operator
char popOp()
{
    return opStack[opTop--];
}

// Check operator priority
int priority(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    if(ch=='*' || ch=='/')
        return 2;
    return 0;
}

// Perform calculation
int calculate(int a, int b, char op)
{
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    if(op=='/') return a/b;
    return 0;
}

int main()
{
    char exp[] = "[1+2*{3+4*(5+6)+(3+2)}]";

    int i = 0;

    while(exp[i] != '\0')
    {
        char ch = exp[i];

        // Number
        if(ch >= '0' && ch <= '9')
        {
            pushValue(ch-'0');
        }

        // Opening brackets
        else if(ch=='(' || ch=='{' || ch=='[')
        {
            pushOp(ch);
        }

        // Closing brackets
        else if(ch==')' || ch=='}' || ch==']')
        {
            while(opStack[opTop]!='(' &&
                  opStack[opTop]!='{' &&
                  opStack[opTop]!='[')
            {
                int b = popValue();
                int a = popValue();
                char op = popOp();

                pushValue(calculate(a,b,op));
            }

            popOp(); // Remove opening bracket
        }

        // Operator
        else
        {
            while(opTop!=-1 &&
                  priority(opStack[opTop]) >= priority(ch))
            {
                int b = popValue();
                int a = popValue();
                char op = popOp();

                pushValue(calculate(a,b,op));
            }

            pushOp(ch);
        }

        i++;
    }

    // Remaining operations
    while(opTop!=-1)
    {
        int b = popValue();
        int a = popValue();
        char op = popOp();

        pushValue(calculate(a,b,op));
    }

    cout << "Answer = " << valStack[valueTop];

    return 0;
}