#include<stdio.h>

int sum(int *a, int m)
{
    if(m==0)
        return 0;
    else
    { return a[m-1] + sum(a, m-1);}
}

int main()
{
    int a[100], n, i, s=0;

    printf("enter number of element\n");
    scanf("%d",&n);

    printf("enter array element\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
        s=s+a[i];

    printf("sum by iter = %d\n",s);
    printf("sum by rec = %d",sum(a,n));

    return 0;
}