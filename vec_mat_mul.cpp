#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>
#define MAX 10
using namespace std;
int main()
{
    int vec[MAX], mat[MAX][MAX], res[MAX];
    srand(time(NULL));
    #pragma omp parallel for
    for(int i=0; i<MAX; i++)
    	vec[i] = rand()%100;
    cout<<"\nVector:"<<endl;
    for(int i=0; i<MAX; i++)
    	cout<<vec[i]<<" ";
    for(int i=0; i<MAX; i++)
    {
        #pragma omp parallel for
        for(int j=0; j<MAX; j++)
    	    mat[i][j] = rand()%100;
    }
    cout<<"\nMatrix:"<<endl;
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
            cout<<mat[i][j]<<"\t";
        cout<<endl;
    }
    #pragma omp parallel for
    for(int i=0; i<MAX; i++)
    	res[i] = 0;
    for(int i=0; i<MAX; i++)
    {
        #pragma omp parallel for
        for(int j=0; j<MAX; j++)
    	    res[i] += mat[i][j]*vec[j];
    }
    cout<<"Result:"<<endl;
    for(int i=0; i<MAX; i++)
    	cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}

