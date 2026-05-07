#include<stdio.h>
#include<string.h>
int main()
{
    typedef struct student { char fname[50];char lname[50]; int roll; } stud;
    stud det[5],temp1,temp;
    int tempm=1,tempn=1;
    for(int i=0; i<5; i++)
    { 
        printf("enter details for student %d : \n",tempm);
        printf("enter first name : ");
        scanf(" %[^\n]",det[i].fname);
        printf("enter last name : ");
        scanf(" %[^\n]",det[i].lname);
        printf("enter roll no. : ");
        scanf("%d",&det[i].roll);
        tempm++;
    }
   for(int i=0; i<5; i++)
   {
    for(int j=0; j<5-i-1; j++)
    {
        if(det[j].roll>det[j+1].roll)
        {
            temp=det[j];
            det[j]=det[j+1];
            det[j+1]=temp;
            strcpy(det[j].fname,temp1.fname);
            strcpy(det[j+1].fname,det[j].fname);                    
            strcpy(temp1.fname,det[j+1].fname);
            strcpy(det[j].lname,temp1.lname);
            strcpy(det[j+1].lname,det[j].lname);                    
            strcpy(temp1.lname,det[j+1].lname);   
        }
    }
}
    for(int i=0; i<5; i++)
    { 
        printf("details for student %d : \n",tempn);
        printf("first name : %s\n",det[i].fname);
        printf("Last name : %s\n",det[i].lname);
        printf("roll no. : %d\n",det[i].roll);
        printf("\n");
        tempn++;
        
    }

   

    /*int temp1;
    char temp2[50],temp3[50];
    int min;
    
   for (int i=0; i<4; i++)
   {
      min=det.roll[i];
      for(int j=i+1; j<5; j++)
      {
        if(det.roll[j]<det.roll[min])
        {
            min=j;
        }

      }
    temp1=det.roll[i];
    det.roll[i]=det.roll[min];
    det.roll[min]=temp1;
    temp2=det.fname[i];
    det.fname[i]=det.fname[min];
    det.fname[min]=temp1;
    temp2=det.lname[i];
    det.lname[i]=det.lname[min];
    det.lname[min]=temp1;

   }
   int tempn=1;
   for(int i=0; i<5; i++)
    { 
        printf("details for student %d : \n",tempn);
        printf("first name : %s\n",det.fname[i]);
        printf("Last name : %s\n",det.lname[i]);
        printf("roll no. : %d\n",det.roll[i]);
        printf("\n");
        tempn++;
    }
   
 */   
}