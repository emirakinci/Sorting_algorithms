#include <stdio.h>
#include <stdlib.h>
void merge(int *buffer, int *tbuffer, int c, int l, int r);
void merge_sort_r(int *buffer, int*tbuffer, int l, int r);
void merge_sort(int *buffer, int N);
int main(void){
    int arr[] = {12, 6, 4, 5, 9, 2, 3, 1};
    int sz = sizeof(arr)/sizeof(int);
    merge_sort(arr, sz);
    for(int i=0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
}
void merge_sort(int *buffer, int N)
{
    int l = 0, r = N-1;
    int *buffer2 = (int*)malloc(N*sizeof(int));
    merge_sort_r(buffer, buffer2, l, r);
}
void merge_sort_r(int *buffer, int *tbuffer, int l, int r)
{
    int c;
    if(l >= r)
    {
        return;
    }
    c = (l+r)/2;
    merge_sort_r(buffer, tbuffer, l, c);
    merge_sort_r(buffer, tbuffer, c+1, r);

    merge(buffer, tbuffer, c, l, r);
}
void merge(int *buffer, int *tbuffer, int c, int l, int r)
{
    int i,j,k;

    for(i=l, j=c+1, k=l; i<=c && j<=r;)
    {
        if(buffer[i] <= buffer[j])
        {
            tbuffer[k++]=buffer[i++];
        }
        else
        {
            tbuffer[k++]=buffer[j++];
        }
    }

    while(i <= c)
    {
        tbuffer[k++] = buffer[i++];
    }
    while(j <= r)
    {
        tbuffer[k++] = buffer[j++];
    }

    for(i=l; i <= r; i++)
    {
        buffer[i] = tbuffer[i];
    }
}