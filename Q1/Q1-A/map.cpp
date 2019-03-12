#include<iostream>
#include<string>
#include<random>
#include<iomanip>
#include<cmath>
#include "map.h"


Map::Map(int n){
  if(n >= 0){N = n;}
  else{std::cout << "please enter a positive number!" << std::endl;}
  
  std::cout << "map created!" << std::endl;
  arr={new int*[N]};//dynamic arr
  for(int i{}; i < N ;i++){
    arr[i] = new int[N];
  }

  for(int i{};i<N;i++)//filling 2x2 danamic arr with random numbers
    for(int j{};j<N;j++)
      {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist100(0,100); // distribution in range [1, 6]
	arr[i][j] = dist100(rng);
      }
  
  }


Map::~Map(){//deleting dynamic arr
 for(int i{}; i < N ;i++){
    delete[] arr[i];
  }
 delete[] arr;
 //std::cout << "destructor of Map" << std::endl;
}
  









void Map::showMap(){//showing filled numbers
  for(int i{};i<N;i++)
    for(int j{};j<N;j++)
      {
	std::cout << std::setw(3) << arr[i][j];
	if(j == N-1)
	  std::cout << std::endl;
      }
}






void Map::findRoute(){

   int sum{},j{},i{};
  for(int k{}; k < 2*N+1 ; k++){
    if(abs(arr[i][j+1] - arr[i][j]) >= abs(arr[i+1][j] - arr[i][j])){
      if(i != N-1){//checking if it is last column or not
	sum += abs(arr[i+1][j] - arr[i][j]);

	i = i+1;
      }
      
      if(i == N-1){//if its last column
	for(int l{0} ; l < N+1 ; l++){
	  if(j == N-1){//means that we are in the last point

	    break;
	    }
	  sum += abs(arr[i][j+1] - arr[i][j]);

	  j = j+1;//we go to the next row
	}
      }
    }

    if(i == (N-1) && j == (N-1)){//checking last point
      break;
    }
    
    if(abs(arr[i][j+1] - arr[i][j]) < abs(arr[i+1][j] - arr[i][j])){
      if(j == N-1){//checking last row
	for(int l{0} ; l < N+1 ; l++){
	  if(i == N-1){
	    //std::cout << "end rasti " << std::endl;
	    break;
	    }
	  sum += abs(arr[i+1][j] - arr[i][j]);

	  i = i+1;
	}
      }
      
      if(j != N-1){//not last row
	sum += abs(arr[i][j+1] - arr[i][j]);

	j = j+1;
      }
      
      }
    if(i == (N-1) && j == (N-1)){//checking last point
      break;
    }

  }
  std::cout << std::endl;
  std::cout << "Distance: " << sum << std::endl;//print the sumation!
}







void Map::showRoute(){

  str={new std::string*[N]};
  for(int i{}; i < N ;i++){
    str[i] = new std::string[N];
  }

  for(int i{};i<N;i++)
    for(int j{};j<N;j++)
      str[i][j] = "-";

  int j{},i{};
  for(int k{}; k < 2*N+1 ; k++){
    if(abs(arr[i][j+1] - arr[i][j]) >= abs(arr[i+1][j] - arr[i][j])){
      if(i != N-1){
	str[i][j] = "+";
	i = i+1;
      }
      
      if(i == N-1){
	for(int l{0} ; l < N+1 ; l++){
	  if(j == N-1){
	    str[i][j] = "+";
	    break;
	    }
	  str[i][j]="+";
	  j = j+1;
	}
      }
    }

    if(i == (N-1) && j == (N-1)){
      str[i][j] = "+";
      break;
    }
    
    if(abs(arr[i][j+1] - arr[i][j]) < abs(arr[i+1][j] - arr[i][j])){
      if(j == N-1){
	for(int l{0} ; l < N+1 ; l++){
	  if(i == N-1){
	    str[i][j] = "+";
	    break;
	    }
	  str[i][j] = "+";
	  i = i+1;
	}
      }
      
      if(j != N-1){
	str[i][j] = "+";
	j = j+1;
      }
      
      }
    if(i == (N-1) && j == (N-1)){
      str[i][j] = "+";
      break;
    }
  }

  std::cout << "Route: " << std::endl;
  
  for(int i{};i<N;i++)
    {
      for(int j{};j<N;j++){
	std::cout << std::setw(3) << str[i][j];
	if(j == N-1)
	  std::cout << std::endl;
      }
    }

  
}




