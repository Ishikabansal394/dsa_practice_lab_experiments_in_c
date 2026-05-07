#include<stdio.h>

int main()
{
    int r1,c1,r2,c2;
    printf("enter row and col for mat1");
    scanf("%d%d",&r1,&c1);
    printf("enter row and col for mat1");
    scanf("%d%d",&r2,&c2);
    int mat1[r1][c1];
    printf("enter matric 1 elements");
    for(int i=0;i<r1;i++)
    {
        for(int j=0;i<c1;j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }
     int mat2[r2][c2];
    printf("enter matric 2 elements");
    for(int i=0;i<r2;i++)
    {
        for(int j=0;i<c2;j++)
        {
            scanf("%d",&mat2[i][j]);
        }
    }
    
    if(c1!=r2)
    {
        printf("not possible");
    }
    else
    {
        int mul[r1][c2];
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c2;j++)
            {
                mul[i][j]=0;
                for(int k=0;k<c1;k++)
                {
                    mul[i][j]=mul[i][j]+mat1[i][k]*mat2[k][j];
                }
            }
        }
    
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c2;j++)
            {
                printf("%d ",mul[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}