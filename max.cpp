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
    int max_val = 0;
    #pragma omp parallel for reduction(max: max_val)
    for(int i=0; i<MAX; i++)
    {
        cout<<"Thread ID = "<<omp_get_thread_num()<<" and i = "<<i<<endl;
        if(a[i] > max_val)
            max_val = a[i];
    }
    cout<<"\n\nMaximum Value = "<<max_val<<endl;
    return 0;
}
