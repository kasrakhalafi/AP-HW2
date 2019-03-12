#include<iostream>
#include"libVec.h"
#include<vector>

libVec::libVec(){
  
}

void libVec::disp(){
  for(auto i = vec.begin(); i != vec.end(); ++i) 
    std::cout << *i << std::endl; 
}

void libVec::counter(int n){
  N=n;
  for(int i{}; i < N ; i++){
    vec.push_back(i);
  } 

  /*for(auto i = vec.begin(); i != vec.end(); ++i)
    cnt += *i;
   std::cout << cnt << std::endl;
  */
}

libVec::~libVec() =default;
