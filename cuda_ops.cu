#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/reduce.h>
#include <cstdlib>
#include <iostream>
#include <functional>
#include <cmath>
using namespace std;
#define SIZE 100

/*
 * @struct varianceshifteop
 * @brief a unary function that shifts input data
 * by their mean and computes the squares of them
 */
struct varianceshifteop : unary_function<float, float>
{
    varianceshifteop(float m) : mean(m)
    { /* no-op */ }

    const float mean;
    
    __device__ float operator()(float data) const
    {
        return pow(data - mean, 2.0f);
    }
};

int main()
{
  // generate some random data on the host
  thrust::host_vector<int> h_vec(SIZE);
  for(int i=0; i<h_vec.size(); i++)
    h_vec[i]=rand()%RAND_MAX;
  // transfer to device
  thrust::device_vector<int> d_vec = h_vec;
   // sum on device
  float mean = thrust::reduce(d_vec.begin(), d_vec.end(), 0.0f, thrust::plus<int>()) / d_vec.size();
  int max_val = thrust::reduce(d_vec.begin(), d_vec.end(), 0, thrust::maximum<int>());
  int min_val = thrust::reduce(d_vec.begin(), d_vec.end(), RAND_MAX, thrust::minimum<int>());
  float variance = thrust::transform_reduce(d_vec.begin(), d_vec.end(), varianceshifteop(mean), 0.0f, thrust::plus<int>()) / (d_vec.size() - 1);
  // standard dev is just a sqrt away
  float stdv = sqrtf(variance);
  cout<<"Mean = "<<mean<<"  Max = "<<max_val<<"  Min = "<<min_val<<" Standard Deviation = "<<stdv<<endl;
  return 0;
}