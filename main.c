#include <stdio.h>
#include <stdlib.h>

void interclasare( int* a, int n, int*b, int m, int*c)
{
    int* aux = (int*)calloc(n+m, sizeof(int));
    int i=0, j =0,k=0;
    while(i < n && j< m )
    {
        if(a[i] <= b[j])
        {
            aux[k] = a[i];
            k++;
            i++;
        }
        else
        {   aux[k] = b[j];
            k++;
            j++;
        }
    }
    while(i < n )
    {
        aux[k] = a[i];
        k++;
        i++;
    }

    while(j<m)
    {
        aux[k] = b[j];
        k++;
        j++;
    }

    for(int i = 0 ; i< k; i++)
    {
        c[i] = aux[i];
    }
}


void mergeSort(int* v , int low, int high)
{
    if(low >= high) return;
    int mid = (low+high)/2;
    mergeSort(v, low, mid);
    mergeSort(v, mid+1, high);
    interclasare(v+low, mid-low+1, v+mid+1, high-mid, v+low); //v+low partea stanga a sirului, mid-low+1 cati term are sirul din stg
}



int main()
{
    int n;
    scanf("%d", &n);
    int x;
    int* v = (int*)calloc(n, sizeof(int));
    for(int i =0 ; i<n; i++)
    {
        scanf("%d", &x);
        v[i]= x;
    }

    mergeSort(v , 0, n-1);
    for(int i=0; i< n; i++)
    {
        printf("%d ", v[i]);
    }

    return 0;
}
