#include "permanent.h"
#include <chrono>
#include <iostream>


inline std::chrono::high_resolution_clock::time_point tic()
{ return std::chrono::high_resolution_clock::now(); }
inline double toc( const std::chrono::high_resolution_clock::time_point& t2)
{ return std::chrono::duration<double>(std::chrono::high_resolution_clock::now()-t2).count(); }

int main(int argc, char** argv)
{

  // Generate a random non-negative matrix
  std::srand((unsigned int) time(0));
  size_t n  = 25;
  Eigen::MatrixXd m = (Eigen::MatrixXd::Random(n,n) + Eigen::MatrixXd::Ones(n,n))/2.0; 
  
  
  auto t1 = tic();
  for(int k = 1; k < 1000; ++k)
    toc(t1);
  
  
  t1 = tic();
  std::cout << permanentApproximation(m,300) << std::endl;
  std::cout << "The elapsed time is " << toc(t1) << " sec." << std::endl;  

  t1 = tic();
  std::cout << permanentApproximationSquare(m,300) << std::endl;
  std::cout << "The elapsed time is " << toc(t1) << " sec." << std::endl;  
  
  t1 = tic();
  std::cout << permanentExact(m) << std::endl;
  std::cout << "The elapsed time is " << toc(t1) << " sec." << std::endl;

  t1 = tic();
  std::cout << permanentExactSquare(m) << std::endl;
  std::cout << "The elapsed time is " << toc(t1) << " sec." << std::endl;
  
  t1 = tic();
  std::cout << permanentExactNx(m) << std::endl;
  std::cout << "The elapsed time is " << toc(t1) << " sec." << std::endl;

  t1 = tic();
  std::cout << permanentExactNxSquare(m) << std::endl;
  std::cout << "The elapsed time is " << toc(t1) << " sec." << std::endl;

  t1 = tic();
  std::cout << permanentFastest(m) << std::endl;
  std::cout << "The elapsed time is " << toc(t1) << " sec." << std::endl;    

  return 0;
}

