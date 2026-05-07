#include<stdio.h>

void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int temp[100];

    while(i <= m && j <= r)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i <= m)
        temp[k++] = a[i++];

    while(j <= r)
        temp[k++] = a[j++];

    for(int i = l, t = 0; i <= r; i++, t++)
        a[i] = temp[t];
}
void mergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main()
{
    int a[] = {5, 3, 8, 4, 2};
    int n = 5;

    mergeSort(a, 0, n-1);

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}