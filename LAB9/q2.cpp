#include<stdio.h>
#include<string.h>
#include "stack.h"
int check(char string[25],stack s1);
int main()
{
    stack s1;
    char string[25];
    printf("Enter the string");
    scanf(" %24s",string);
    printf("The count of ideal substring=%d",check(string,s1));
    return 0;
}

int check(char string[25],stack s1)
{  
    int count=0;
    char a,b,c;
    for(int i =0;string[i+2]!='\0';i++)
    {
        s1.push(string[i]);
        s1.push(string[i+1]);
        s1.push(string[i+2]);

        a=s1.pop();
        b=s1.pop();
        c=s1.pop();

        if(a!=b && b!=c && a!=c)
        {
            count ++;
        }
    }
    return count;
}