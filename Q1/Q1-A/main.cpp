#include <iostream>
#include "map.h"
#include<cmath>

int main()
{
  //srand((unsigned)time(0)); 
  //int i;
  //i = (rand()%101); 
  //std::cout << i << "\n"; 
  Map map{10};
  map.showMap();
  map.findRoute();
  map.showRoute();
  return 0;
}
