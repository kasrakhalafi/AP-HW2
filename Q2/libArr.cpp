#include "libArr.h"
#include<iostream>

libArr::libArr(){
  
}


void libArr::disp(){
  for(int i{}; i<N ; i++)
    {
      std::cout << arr[i] << std::endl;
    }
}

libArr::~libArr(){
  delete arr;
}

void libArr::counter(int n){
  N=n;
  arr = new int [N];
  for(int i{}; i < N ; i++)
    {
      arr[i] = i;
    }
}
