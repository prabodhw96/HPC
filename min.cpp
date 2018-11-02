#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>
using namespace std;
#define MAX 100
int main()
{
    srand(time(NULL));
    int a[MAX];
    omp_set_num_threads(4);
    for(int i=0; i<MAX; i++)
        a[i] = rand()%1000;
    cout<<"Array: "<<endl;
    for(int i=0; i<MAX; i++)
        cout<<a[i]<<"\t";
    int min_val = 9999;
    #pragma omp parallel for reduction(min: min_val)
    for(int i=0; i<MAX; i++)
    {
        cout<<"Thread ID = "<<omp_get_thread_num()<<" and i = "<<i<<endl;
        if(a[i] < min_val)
            min_val = a[i];
    }
    cout<<"\n\nMinimum Value = "<<min_val<<endl;
    return 0;
}
