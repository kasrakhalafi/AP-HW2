#include<iostream>
#include<chrono>
#include<functional>
#include "libArr.h"
#include "libVec.h"

template<class C>
long int runTime(void (C::*funct)(int),int n);
  
int main()
{
  void(libArr::* ptrfunc)(int) = &libArr::counter;
  void(libVec::* ptrfunct)(int) = &libVec::counter;
  std::cout << "Time of Array: " << runTime(ptrfunc,1000000) << std::endl;
  std::cout << "Time of Vector: " << runTime(ptrfunct,1000000) << std::endl;
  return 0;
}

template<class C>

long int runTime(void (C::*funct)(int),int n){
  auto start = std::chrono::high_resolution_clock::now();
  C a;
  (a.*funct)(n);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  return duration.count();
}
