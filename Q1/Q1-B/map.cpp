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
  arr={new int*[N]};
  for(int i{}; i < N ;i++){
    arr[i] = new int[N];
  }

  for(int i{};i<N;i++)
    for(int j{};j<N;j++)
      {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist100(0,100); // distribution in range [1, 6]
	arr[i][j] = dist100(rng);
      }
  }


Map::~Map(){
 for(int i{}; i < N ;i++){
    delete[] arr[i];
  }
 delete[] arr;
 //std::cout << "destructor of Map" << std::endl;
}


void Map::showMap(){
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
    if((j != N-1) && (i != N-1)){
      if((abs(arr[i][j+1] - arr[i][j]) >= abs(arr[i+1][j] - arr[i][j])) && ((abs(arr[i+1][j+1] - arr[i][j]) > abs(arr[i][j] - arr[i][j])))){
	if(i != N-1){
	  sum += abs(arr[i+1][j] - arr[i][j]);
	  //std::cout << "payini 1 2: " << arr[i+1][j] << "-" << arr[i][j] << "= " << sum << std::endl;
	  i = i+1;
	}
	
	if(i == N-1){
	  for(int l{0} ; l < N+1 ; l++){
	    if(j == N-1){
	      //std::cout << "end payini " << std::endl;
	    break;
	    }
	    sum += abs(arr[i][j+1] - arr[i][j]);
	    //std::cout << "payini 1 1: " << sum << std::endl;
	    j = j+1;
	  }
	}
      }
      
      if(i == (N-1) && j == (N-1)){
	break;
      }
      
      if((abs(arr[i][j+1] - arr[i][j]) < abs(arr[i+1][j] - arr[i][j])) && (abs(arr[i][j+1] - arr[i][j]) < abs(arr[i+1][j+1] - arr[i][j]))){
	if(j == N-1){
	  for(int l{0} ; l < N+1 ; l++){
	    if(i == N-1){
	      //std::cout << "end rasti " << std::endl;
	      break;
	    }
	  sum += abs(arr[i+1][j] - arr[i][j]);
	  //std::cout << "rast 1 1: " << arr[i+1][j] << "-" << arr[i][j] << "= " << sum << std::endl;
	  i = i+1;
	  }
	}
	
	if(j != N-1){
	  sum += abs(arr[i][j+1] - arr[i][j]);
	  //std::cout << "rast 1 2: " << arr[i][j+1] << "-" << arr[i][j] << "= " << sum  << std::endl;
	  j = j+1;
	}
	if(j == N-1){
	  for(int l{0} ; l < N+1 ; l++){
	    if(i == N-1){
	      //std::cout << "end rasti " << std::endl;
	      break;
	    }
	  sum += abs(arr[i+1][j] - arr[i][j]);
	  //std::cout << "rast 1 1: " << arr[i+1][j] << "-" << arr[i][j] << "= " << sum << std::endl;
	  
	  i = i+1;
	  }
	  if(i == N-1)
	    break;
	}
      }
      
      if((abs(arr[i+1][j+1] - arr[i][j]) <= abs(arr[i+1][j] - arr[i][j])) && (abs(arr[i+1][j+1] - arr[i][j]) <= abs(arr[i][j+1] - arr[i][j]))){
	sum += abs(arr[i+1][j+1] - arr[i][j]);
	//std::cout << "Movarrab 2: " << arr[i+1][j+1] << "-" << arr[i][j] << "=" << sum << std::endl;
	i = i+1;
	j = j+1;

	if(i == N-1){
	  for(int l{0} ; l < N+1 ; l++){
	    if(j == N-1){
	      //std::cout << "end payini " << std::endl;
	      break;
	    }
	    sum += abs(arr[i][j+1] - arr[i][j]);
	    //std::cout << "Movarab rast 1 1: " << sum << std::endl;
	    j = j+1;
	  }
	}



	if(j == N-1){
	  for(int l{0} ; l < N+1 ; l++){
	    if(i == N-1){
	      //std::cout << " " << std::endl;
	      break;
	    }
	  sum += abs(arr[i+1][j] - arr[i][j]);
	  //std::cout << "Movarrab payin 1 1: " << arr[i+1][j] << "-" << arr[i][j] << "= " << sum << std::endl;
	  i = i+1;
	  }
	}

	if((j == N-1) && (i == N-1))
	  break;
	
        
	//std::cout << "round: " << k << std::endl;
      }
    }    

    if(!((j != N-1) && (i != N-1))){

      if(abs(arr[i][j+1] - arr[i][j]) >= abs(arr[i+1][j] - arr[i][j])){
	if(i != N-1){
	  sum += abs(arr[i+1][j] - arr[i][j]);
	  //std::cout << "payini 2 2: " << arr[i+1][j] << "-" << arr[i][j] << "= " << sum << std::endl;
	  i = i+1;
	}
	
	if(i == N-1){
	  for(int l{0} ; l < N+1 ; l++){
	    if(j == N-1){
	      //std::cout << "end payini " << std::endl;
	      break;
	    }
	    sum += abs(arr[i][j+1] - arr[i][j]);
	    //std::cout << "payini 2 1: " << sum << std::endl;
	    j = j+1;
	  }
	}
      }
      
      if(i == (N-1) && j == (N-1)){
	break;
      }
      
      if(abs(arr[i][j+1] - arr[i][j]) < abs(arr[i+1][j] - arr[i][j])){
	if(j == N-1){
	  for(int l{0} ; l < N+1 ; l++){
	    if(i == N-1){
	      //std::cout << "end rasti " << std::endl;
	      break;
	    }
	    sum += abs(arr[i+1][j] - arr[i][j]);
	    //std::cout << "rast 2 1: " << arr[i+1][j] << "-" << arr[i][j] << "= " << sum << std::endl;
	    i = i+1;
	  }
	}
	
	if(j != N-1){
	  sum += abs(arr[i][j+1] - arr[i][j]);
	  //std::cout << "rast 2 2: " << arr[i][j+1] << "-" << arr[i][j] << "= " << sum  << std::endl;
	  j = j+1;
	}
	
      }
      if(i == (N-1) && j == (N-1)){
	break;
      }
    }
  }
  std::cout << std::endl;
  std::cout << "Distance: " << sum << std::endl;
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
    if((j != N-1) && (i != N-1)){
      if((abs(arr[i][j+1] - arr[i][j]) >= abs(arr[i+1][j] - arr[i][j])) && ((abs(arr[i+1][j+1] - arr[i][j]) > abs(arr[i][j] - arr[i][j])))){
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
	    str[i][j] = "+";
	    
	    j = j+1;
	  }
	}
      }
      
      if(i == (N-1) && j == (N-1)){
	str[i][j] = "+";
	break;
      }
      
      if((abs(arr[i][j+1] - arr[i][j]) < abs(arr[i+1][j] - arr[i][j])) && (abs(arr[i][j+1] - arr[i][j]) < abs(arr[i+1][j+1] - arr[i][j]))){
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
	if(j == N-1){
	  for(int l{0} ; l < N+1 ; l++){
	    if(i == N-1){
	      str[i][j] = "+";
	      break;
	    }
	    str[i][j] = "+";
	  
	  
	    i = i+1;
	  }
	  if(i == N-1){
	    str[i][j] = "+";
	    break;
	  }
	}
      }
      
      if((abs(arr[i+1][j+1] - arr[i][j]) <= abs(arr[i+1][j] - arr[i][j])) && (abs(arr[i+1][j+1] - arr[i][j]) <= abs(arr[i][j+1] - arr[i][j]))){
	str[i][j] = "+";
	
	i = i+1;
	j = j+1;
	str[i][j] = "+";
	if(i == N-1){
	  for(int l{0} ; l < N+1 ; l++){
	    if(j == N-1){
	      str[i][j] = "+";
	      break;
	    }
	    str[i][j] = "+";

	    j = j+1;
	    str[i][j] = "+";
	  }
	}



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

	if((j == N-1) && (i == N-1)){
	  str[i][j] = "+";
	  break;
	}
	
        

      }
    }    

    if(!((j != N-1) && (i != N-1))){
      
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
	    str[i][j] = "+";
	    
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
	  str[i][j] = "+";
	}
	
      }
      if(i == (N-1) && j == (N-1)){
	str[i][j] = "+";
	break;
      }
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



/*void Map::~showRoute(){
  for(int i{}; i < N ;i++){
    delete[] str[i];
  }
  delete[] str;
  std::cout << "destructor of showRoute created!! " << std::endl;

  }*/
