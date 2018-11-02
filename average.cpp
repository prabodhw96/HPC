#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>
using namespace std;
#define MAX 50
int main()
{
    srand(time(NULL));
    int a[MAX];
    float avg=0.0;
    for(int i=0; i<MAX; i++)
        a[i] = rand()%MAX;
    for(int i=0; i<MAX; i++)
        cout<<a[i]<<"\t";
    #pragma omp parallel
    for(int i=0; i<MAX; i++)
    {
        avg += a[i];
        cout<<"For i = "<<i<<" thread "<<omp_get_thread_num()<<" is executing "<<endl;
    }
    avg /= MAX;
    cout<<"\nAverage = "<<avg<<endl;
    return 0;
}
