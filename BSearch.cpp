#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <omp.h>
using namespace std;
#define n 100

int binarySearch(int a[], int target)
{
  int low=0, high=n, mid;
  bool abort = false;
  #pragma omp parallel
  while(low<=high && !abort)
  {
    mid=(low+high)/2;
    if(a[mid]<target)
      low=mid+1;
    else if(a[mid]>target)
      high=mid-1;
    else
      abort = true;
  }
  if(abort)
    return mid;
  return -1;
}
int main()
{
  int a[n];
  srand(time(NULL));
  for(int i=0; i<n; i++)
    a[i] = rand()%1000;
  sort(a, a+n);
  cout<<"Your sorted array is: ";
  for(int i=0; i<n; i++)
      cout<<a[i]<<" ";
  cout<<"\nEnter the number you want to find: ";
  int target;
  cin>>target;
  (binarySearch(a, target) == -1)?cout<<"Key not found":cout<<"Key found at index "<<binarySearch(a, target)<<endl;
  return 0;
}
