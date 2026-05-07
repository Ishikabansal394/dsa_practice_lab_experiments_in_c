#include<stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while(1)
    {
        while(i <= high && a[i] <= pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
            break;
    }

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }
}

int main()
{
    int a[] = {5, 3, 8, 4, 2};
    int n = 5;

    quickSort(a, 0, n-1);

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}