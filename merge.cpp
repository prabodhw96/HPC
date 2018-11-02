#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>
using namespace std;
#define n 500
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int a[],int l,int r)
{
    int mid;
    if(l<r)
    {
        mid=(l+r)/2;
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                mergesort(a,l,mid);
            }
            #pragma omp section
            {
                mergesort(a,mid+1,r);
            }
        }
        merge(a, l, mid, r);
    }
}
int main()
{
    clock_t start, finish;
    start = clock();
    srand(time(NULL));
    int a[n];
    for(int i=0; i<n; i++)
        a[i] = rand()%1000;
    cout<<"Before sorting: "<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    mergesort(a,0,n-1);
    cout<<"After sorting: "<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    finish = clock();
    cout<<"\nExecution Time: "<<finish - start<<" microseconds"<<endl;
    return 0;
}
