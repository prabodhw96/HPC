#include <iostream>
#include <cstdlib>
#include <omp.h>
using namespace std;
#define MAX 100
int main()
{
    int a[MAX], b[MAX], c[MAX];
    srand(time(NULL));
    #pragma omp parallel for
    for(int i=0; i<MAX; i++)
    	a[i] = rand()%1000;
    cout<<"First vector: "<<endl;
    for(int i=0; i<MAX; i++)
    	cout<<a[i]<<" ";
    cout<<endl;
    #pragma omp parallel for
    for(int i=0; i<MAX; i++)
    	b[i] = rand()%1000;
    cout<<"Second vector: "<<endl;
    for(int i=0; i<MAX; i++)
    	cout<<b[i]<<" ";
    cout<<endl;
    #pragma omp parallel for
    for(int i=0; i<MAX; i++)
    	c[i] = a[i] + b[i];
    cout<<"First vector + Second vector: "<<endl;
    for(int i=0; i<MAX; i++)
    	cout<<a[i]<<" + "<<b[i]<<" = "<<c[i]<<endl;
    return 0;
}

