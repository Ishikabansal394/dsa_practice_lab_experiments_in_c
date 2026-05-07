#include<stdio.h>

int main()
{
    int r1,c1;
    printf("enter row and col for mat1 ");
    scanf("%d %d",&r1,&c1);
    int mat1[r1][c1];
    printf("enter matric 1 elements");
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }
    int sum_row=0;
    for(int i=0; i<r1; i++)
    {
        int sr=0;
        for(int j=0; j<c1; j++)
        {
          sr=sr+mat1[i][j];
          
        }
        printf("sum of row %d is %d\n",r1+1, sr);
        sum_row=sum_row+sr;
       
    }
     printf("sum of all rows is%d\n",sum_row);
    int sum_col=0;
    for(int i=0; i<c1; i++)
    {
        int sc=0;
        for(int j=0; j<r1; j++)
        {
          sc=sc+mat1[j][i];
          
        }
        printf("sum of column %d is %d\n",c1+1, sc);
        sum_col=sum_col+sc;
    }
     printf("sum of all columns is %d\n",sum_col);
}