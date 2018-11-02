#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>
using namespace std;
#define MAX 100
int main()
{
    srand(time(NULL));
    int a[MAX], b[MAX], sum=0;
    for(int i=0; i<MAX; i++)
        a[i] = rand()%MAX;
    cout<<"Array 1: "<<endl;
    for(int i=0; i<MAX; i++)
        cout<<a[i]<<"\t";
    for(int i=0; i<MAX; i++)
        b[i] = rand()%MAX;
    cout<<"\nArray 2: "<<endl;
    for(int i=0; i<MAX; i++)
        cout<<b[i]<<"\t";
    #pragma omp parallel for reduction(+:sum)
    for(int i=0; i<MAX; i++)
        sum += a[i]*b[i];
    cout<<"\n\nSum = "<<sum<<endl;
    return 0;
}
