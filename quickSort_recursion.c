#include <stdio.h>
// avoid using quick sort when the array is already ordered. The cost will be quadratic in that case.
void quickSort_w(int *buffer, int N); // wrapper function
void quickSort(int *buffer, int l, int r);
int partition(int *buffer, int l, int r);
void swap(int *buf, int i1, int i2);

int main(void){
    int arr[] = {5, 1, 9, 13, 4, 6, 0, 8};
    int sz = sizeof(arr)/sizeof(int);
    quickSort_w(arr, sz);
    for(int i=0; i<sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
void quickSort_w(int *buffer, int N)
{
    int lm = 0, rm = N-1;
    quickSort(buffer, lm, rm);
}
void quickSort(int *buffer, int l, int r)
{
    int c;
    if(r<=l)
    {
        return;
    }
    c = partition(buffer, l, r);
    quickSort(buffer, l, c-1);
    quickSort(buffer, c+1, r);
    return ;
}
int partition(int *buffer, int l, int r)
{
    int pivot = buffer[r];
    int i = l-1, j = r;
    int tmp;

    while(i<j)
    {
        while(buffer[i]<pivot)
        {
            i++;
        }
        while(j>l && buffer[j]>=pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(buffer, i, j);
        }
    }
    swap(buffer, i, r);
    return i;
}
void swap(int *buf, int i1, int i2)
{
    int tmp;
    tmp = buf[i1];
    buf[i1] = buf[i2];
    buf[i2] = tmp;
}