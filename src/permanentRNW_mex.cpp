#include <vector>
#include "mex.h"

// Compile: mex permanentRNW_mex.cpp

//A. Nijenhuis and H.S. Wilf. Combinatorial Algorithms for Computers and Calculators, 2nd ed. Academic Press, New York-London, 1978.
double permanent(const double* a, const int n)
{
  double p = -1.0;
  std::vector<double> x(n);
  for(int i = 0; i < n; ++i)
  {
    x[i] = a[i*n+n-1];
    for(int j = 0; j < n; ++j)
      x[i] -= a[i*n+j]/2.0;
    p = p * x[i];
  }

  double s = -1.0;
  std::vector<int> g(n,0);
  int two_n1 = (1<<(n-1));
  int j = 0;
  for(int k = 2; k <= two_n1; ++k)
  {
    if( k % 2 ){
      j = 1;
      for(int m = 0; m<n; ++m)
        if(g[m] == 0)
          j += 1;
        else
          break;
    }else
      j = 0;
    
    int z = 1-2*g[j];
    g[j] = 1-g[j];
    s = -s;
    double t = s;
    for(int i = 0; i < n; ++i)
    {
      x[i] += z*a[i*n+j];
      t = t*x[i];
    }
    p += t;
  }

  if( n % 2 )
    return -2*p;
  else
    return 2*p;
}


void mexFunction( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{
/*
 * @INPUT:
 * A = n x n matrix whose permanent to compute
 */
 
	// get the input from matlab
	const double* a = mxGetPr(prhs[0]);
	const int n = mxGetM(prhs[0]);
	
	// compute permanent
	double p = permanent(a,n);
	
	// set output for matlab
	plhs[0] = mxCreateDoubleScalar(p);
}

