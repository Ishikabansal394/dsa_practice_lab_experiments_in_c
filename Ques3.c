#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    int i;

    printf("enter the string\n");
    scanf("%[^\n]",s);

    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]>=65 && s[i]<=90)
            s[i]=s[i]+32;
    }

    printf("lowercase string is\n");
    puts(s);

    return 0;
}