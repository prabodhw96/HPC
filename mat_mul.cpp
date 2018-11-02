#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>
#define MAX 10
using namespace std;
int main()
{
    int mat1[MAX][MAX], mat2[MAX][MAX], prod[MAX][MAX];
    srand(time(NULL));
    for(int i=0; i<MAX; i++)
    {
        #pragma omp parallel for
        for(int j=0; j<MAX; j++)
    	    mat1[i][j] = rand()%100;
    }
    cout<<"\nMatrix 1:"<<endl;
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
            cout<<mat1[i][j]<<"\t";
        cout<<endl;
    }
    for(int i=0; i<MAX; i++)
    {
        #pragma omp parallel for
        for(int j=0; j<MAX; j++)
    	    mat2[i][j] = rand()%100;
    }
    cout<<"\nMatrix 2:"<<endl;
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
            cout<<mat2[i][j]<<"\t";
        cout<<endl;
    }
    int k, sum=0;
	for(int i=0; i<MAX; i++)
	{
        for(int j=0; j<MAX; j++)
        {
            #pragma omp parallel for
            for(k=0; k<MAX; k++)
				sum += mat1[i][k]*mat2[k][j];
            prod[i][j] = sum;
            sum = 0;
        }
	}
	cout<<"\nProduct Matrix:"<<endl;
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
            cout<<prod[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
