#include <stdio.h>
#define N 5
int *merge(int *v1, int *v2, int *v3, int n);
int main(void){

    int buff1[N] = {3, 6, 9, 40, 30};
    int buff2[N] = {-1, 6, 7, 8, 10};
    int buff3[2*N];

    int *result;

    result = merge(buff1, buff2, buff3, N);

    for(int j=0; j < 2*N; j++)
    {
        printf("%d\t", *(result+j));
    }
    return 0;
}
int *merge(int *v1, int *v2, int *v3, int n)
{
    int index_1 = 0, index_2 = 0, index_3 = 0;

    while(index_1 < n && index_2 < n)
    {
        if(v1[index_1] < v2[index_2]){
            v3[index_3] = v1[index_1];
            index_3++;
            index_1++;
        }
        else
        {
            v3[index_3] = v2[index_2];
            index_3++;
            index_2++;
        }
    }
    // In our example, after the insertion of 10 inside v3, the main while loop terminates b.c. of index_2 > n
    // Thus, we implement the following 2 while loops in order to insert the possible remaining values from v1
    while(index_1 < n)
    {
        for(int j = index_1+1; j < n; j++)
        {
            int tmp;
            if(v1[index_1] > v1[j])
            {
                tmp = v1[j];
                v1[j] = v1[index_1];
                v1[index_1] = tmp;
            }
        }
        v3[index_3] = v1[index_1];
        index_1++;
        index_3++;
    }
    while(index_2 < n)
    {
        for(int j = index_2+1; j < n; j++)
        {
            int tmp;
            if(v1[index_2] > v1[j])
            {
                tmp = v1[j];
                v1[j] = v1[index_2];
                v1[index_2] = tmp;
            }
        }
        v3[index_3] = v2[index_2];
        index_2++;
        index_3++;
    }
    return v3;
}