#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>
using namespace std;
#define n 500
void bubble(int a[])
{
    for(int i=0; i<n; i++)
    {
    	int first = i%2;
        #pragma omp parallel shared(a, first)
        for(int j=first; j<n-1; j+=2)
        {
            if(a[j] > a[j+1])
               swap(a[j], a[j+1]);
        }
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
	bubble(a);
	cout<<"After sorting: "<<endl;
	for(int i=0; i<n; i++)
	    cout<<a[i]<<" ";
	cout<<endl;
	finish = clock();
    cout<<"\nExecution Time: "<<finish - start<<" microseconds"<<endl;
	return 0;
}
