#include<stdio.h>

int main()
{
    int ch;
    printf("choose the task u want to perform\n");
    printf("1 for insertion at desired location\n");
    printf("2 for deletion from desired location\n");
    printf("3 for linear search\n");
    printf("4 for binary search\n");
    printf("5 for bubble sort\n");
    printf("6 for selection sort\n");
    printf("7 for exit\n");

    scanf("%d",&ch);



    int n;
    printf("enter the number of element in array\n");
    scanf("%d",&n);

    int arr[100];
    printf("enter array elements\n");



    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    while(1){
    switch(ch)
    {
        case 1:
        {
            int m,p;
            printf("enter the element u want to insert\n");
            scanf("%d",&m);
            printf("enter the index where u want to insert\n");
            scanf("%d",&p);

            for(int i=n;i>p;i--)
                arr[i]=arr[i-1];

            arr[p]=m;
            n++;

            for(int i=0;i<n;i++)
                printf("%d ",arr[i]);
            break;
        }

        case 2:
        {
            int d;
            printf("enter the index where u want to delete\n");
            scanf("%d",&d);

            for(int i=d;i<n-1;i++)
                arr[i]=arr[i+1];

            n--;

            for(int i=0;i<n;i++)
                printf("%d ",arr[i]);
            break;
        }

        case 3:
        {
            int k,index=-1;
            printf("enter element u want to search\n");
            scanf("%d",&k);

            for(int i=0;i<n;i++)
            {
                if(arr[i]==k)
                {
                    index=i;
                    break;
                }
            }

            if(index!=-1)
                printf("%d is found at %d index",k,index);
            else
                printf("element is not found");
            break;
        }

        case 4:
        {
            int key,f=0,l=n-1,mid,temp=0;
            printf("enter the element which u want to search\n");
            scanf("%d",&key);

            for(int i=0;f<=l;i++)
            {
                mid=(f+l)/2;
                if(arr[mid]==key)
                {
                    printf("%d is found at %d index",key,mid);
                    temp=1;
                    break;
                }
                else if(key<arr[mid])
                    l=mid-1;
                else
                    f=mid+1;
            }

            if(temp==0)
                printf("element is not found");
            break;
        }

        case 5:
        {
            int t;
            for(int i=0;i<n-1;i++)
                for(int j=0;j<n-1-i;j++)
                    if(arr[j]>arr[j+1])
                    {
                    t=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=t;
                    }

            for(int i=0;i<n;i++)
                printf("%d ",arr[i]);
            break;
        }

        case 6:
        {
            int t,min;
            for(int i=0;i<n-1;i++)
            {
                min=i;
                for(int j=i+1;j<n;j++)
                    if(arr[j]<arr[min])
                    { min=j;}
                    else continue;

                t=arr[i];
                arr[i]=arr[min];
                arr[min]=t;
            }

            for(int i=0;i<n;i++)
                printf("%d ",arr[i]);
            break;
        }
        case 7:
            printf("exiting the program\n");
            break;
    
            
    }

    }

    return 0;
}